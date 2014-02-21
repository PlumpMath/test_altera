/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 *
 * Copyright (C) 2012-2014 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of VectorBlox Computing Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This agreement shall be governed in all respects by the laws of the Province
 * of British Columbia and by the laws of Canada.
 *
 * This file is part of the VectorBlox MXP Software Development Kit.
 *
 */


#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#ifndef __VBX_VECTOR_HPP
#error "This header should not not be directly\
included, include vbx_vector.hpp instead"
#else
template<typename T,typename U,typename V>
void inline vbxx_dim(int dim,vinstr_t v_op, T dest, U srcA, V srcB)
{
	switch(dim){
	case 1:
		vbxx(v_op,dest,srcA,srcB);
		break;
	case 2:
		vbxx_2D(v_op,dest,srcA,srcB);
		break;
	case 3:
		vbxx_3D(v_op,dest,srcA,srcB);
		break;
	}
}
template<typename T,typename U>
inline void vbxx_dim(int dim,vinstr_t v_op, T dest, U srcA)
{
	switch(dim){
	case 1:
		vbxx(v_op,dest,srcA);
		break;
	case 2:
		vbxx_2D(v_op,dest,srcA);
		break;
	case 3:
		vbxx_3D(v_op,dest,srcA);
		break;
	}
}
template<typename T,typename U,typename V>
inline void vbxx_acc_dim(int dim,vinstr_t v_op, T dest, U srcA,V srcB)
{
	switch(dim){
	case 1:
		vbxx_acc(v_op,dest,srcA,srcB);
		break;
	case 2:
		vbxx_acc_2D(v_op,dest,srcA,srcB);
		break;
	case 3:
		vbxx_acc_3D(v_op,dest,srcA,srcB);
		break;
	}
}
// These constructors have to be inline, or else I have to put them in
// a seperately compiled file, and I really don't feel like doing that.
// If it is a bad idea to inline them, hopefully the compiler figures
// that out. They are specialized in order to prevent the programmer
// from making a vector of floats or something stupid like that. If
// the constructor is missing i.e. for float the compiler errors should
// be more informative.
#define MK_CONSTRUCTORS(type,dim)	  \
	template<> \
	inline Matrix< type ,dim>::Matrix(int  size_d1,int size_d2,int size_d3) \
	{ \
		vbx_sp_push(); \
		dimensions[0]=size_d1;dimensions[1]=size_d2;dimensions[2]=size_d3;\
		data=( type *)vbx_sp_malloc(get_size()*sizeof(*data)); \
	} \

#define MK_CON_(dim)\
	MK_CONSTRUCTORS(vbx_word_t,dim) \
	MK_CONSTRUCTORS(vbx_half_t,dim) \
	MK_CONSTRUCTORS(vbx_byte_t,dim) \
	MK_CONSTRUCTORS(vbx_uword_t,dim) \
	MK_CONSTRUCTORS(vbx_uhalf_t,dim) \
	MK_CONSTRUCTORS(vbx_ubyte_t,dim)
MK_CON_(1)
MK_CON_(2)
MK_CON_(3)

template<typename T,int Dim>
Matrix<T,Dim>::Matrix(const Matrix<T,Dim>& cp)
{
	vbx_sp_push();
	dimensions[0]=cp.dimensions[0];
	dimensions[1]=cp.dimensions[1];
	dimensions[2]=cp.dimensions[2];
	data=(T *)vbx_sp_malloc(get_size()*sizeof(*data));
	vbxx_dim(Dim,VMOV,this->data,cp.data);
}
template<typename T,int Dim>
template<typename U,int D>
Matrix<T,Dim>::Matrix(const Matrix<U,D>& cp)
{
	vbx_sp_push();
	dimensions[0]=cp.dimensions[0];
	dimensions[1]=cp.dimensions[1];
	dimensions[2]=cp.dimensions[2];
	data=(T *)vbx_sp_malloc(get_size()*sizeof(*data));
	vbxx_dim(Dim,VMOV,this->data,cp.data);
}

template<typename T,int Dim>
Matrix<T,Dim>::~Matrix(){
	vbx_sp_pop();
}

template<typename T,int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator=(vbx_word_t K)
{
	bool is_signed=(T)-1<0;
	if (is_signed){
		vbxx_dim(Dim,VMOV,this->data,K);
	}else{
		vbxx_dim(Dim,VMOV,this->data,(vbx_uword_t)K);
	}
	return *this;
}
template<typename T,int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator=(const Matrix<T,Dim>& cp){
	vbxx_dim(Dim,VMOV,this->data,cp.data);
	return *this;
}
template<typename T, int Dim>
template<typename U, int D>
Matrix<T,Dim>& Matrix<T,Dim>::operator=(const Matrix<U,D>& cp)
{

	//Infer the types, compiler should optimize the comparisons out
	//signedness is always the same as the lhs argument
	bool is_signed=(U)-1<0;
	if	(((U*)0)+1 ==(U*)4){
		if	(((T*)0)+1 ==(T*)4){
			if(is_signed)
				vbxx_dim(Dim,VMOV,(vbx_word_t*)this->data,(vbx_word_t*)cp.data);
			else
				vbxx_dim(Dim,VMOV,(vbx_uword_t*)this->data,(vbx_uword_t*)cp.data);
		}
		if	(((T*)0)+1 ==(T*)2){
			if(is_signed)
				vbxx_dim(Dim,VMOV,(vbx_half_t*)this->data,(vbx_word_t*)cp.data);
			else
				vbxx_dim(Dim,VMOV,(vbx_uhalf_t*)this->data,(vbx_uword_t*)cp.data);
		}
		if	(((T*)0)+1 ==(T*)1){
			if (is_signed)
				vbxx_dim(Dim,VMOV,(vbx_byte_t*)this->data,(vbx_word_t*)cp.data);
			else
				vbxx_dim(Dim,VMOV,(vbx_ubyte_t*)this->data,(vbx_uword_t*)cp.data);
		}
	}
	if	(((U*)0)+1 ==(U*)2){
		if	(((T*)0)+1 ==(T*)4){
			if(is_signed)
				vbxx_dim(Dim,VMOV,(vbx_word_t*)this->data,(vbx_half_t*)cp.data);
			else
				vbxx_dim(Dim,VMOV,(vbx_uword_t*)this->data,(vbx_uhalf_t*)cp.data);
		}
		if	(((T*)0)+1 ==(T*)2){
			if(is_signed)
				vbxx_dim(Dim,VMOV,(vbx_half_t*)this->data,(vbx_half_t*)cp.data);
			else
				vbxx_dim(Dim,VMOV,(vbx_uhalf_t*)this->data,(vbx_uhalf_t*)cp.data);
		}
		if	(((T*)0)+1 ==(T*)1){
			if (is_signed)
				vbxx_dim(Dim,VMOV,(vbx_byte_t*)this->data,(vbx_half_t*)cp.data);
			else
				vbxx_dim(Dim,VMOV,(vbx_ubyte_t*)this->data,(vbx_uhalf_t*)cp.data);
		}

	}
	if	(((U*)0)+1 ==(U*)1){
		if	(((T*)0)+1 ==(T*)4){
			if(is_signed)
				vbxx_dim(Dim,VMOV,(vbx_word_t*)this->data,(vbx_byte_t*)cp.data);
			else
				vbxx_dim(Dim,VMOV,(vbx_uword_t*)this->data,(vbx_ubyte_t*)cp.data);
		}
		if	(((T*)0)+1 ==(T*)2){
			if(is_signed)
				vbxx_dim(Dim,VMOV,(vbx_half_t*)this->data,(vbx_byte_t*)cp.data);
			else
				vbxx_dim(Dim,VMOV,(vbx_uhalf_t*)this->data,(vbx_ubyte_t*)cp.data);
		}
		if	(((T*)0)+1 ==(T*)1){
			if (is_signed)
				vbxx_dim(Dim,VMOV,(vbx_byte_t*)this->data,(vbx_byte_t*)cp.data);
			else
				vbxx_dim(Dim,VMOV,(vbx_ubyte_t*)this->data,(vbx_ubyte_t*)cp.data);
		}
	}
	return *this;
}

#define MK_VV_OP(OP,INST)	  \
	template<typename U, int D> \
	Matrix<U,D> operator OP (const Matrix<U,D> &lhs,const Matrix<U,D>& rhs) \
	{ \
		Matrix<U,D> temp(lhs.dimensions[0],\
		                 lhs.dimensions[1], \
		                 lhs.dimensions[2]); \
		vbxx_dim(D,INST,temp.data,lhs.data,rhs.data); \
		return temp; \
	} \
	template<typename U, int D> \
	Matrix<U,D> operator OP (const Matrix<U,D> &lhs,const struct Matrix<U,D>::Enumerated rhs) \
	{ \
		Matrix<U,D> temp(lhs.dimensions[0], \
		                 lhs.dimensions[1], \
		                 lhs.dimensions[2]); \
		vbxx_dim(D, INST ,temp.data,lhs.data,(vbx_enum_t*)0); \
		return temp; \
	}

MK_VV_OP(+,VADD)
MK_VV_OP(-,VSUB)
MK_VV_OP(*,VMUL)
MK_VV_OP(&,VAND)
MK_VV_OP(|,VOR)
MK_VV_OP(^,VXOR)
MK_VV_OP(<<,VSHL)
MK_VV_OP(>>,VSHR)
#define Bit(N,n) ((N>>n)&1)

template<class T>
struct unsigned_cast;
template<>struct unsigned_cast<vbx_word_t>{typedef vbx_uword_t type;};
template<>struct unsigned_cast<vbx_half_t>{typedef vbx_uhalf_t type;};
template<>struct unsigned_cast<vbx_byte_t>{typedef vbx_ubyte_t type;};
template<>struct unsigned_cast<vbx_uword_t>{typedef vbx_uword_t type;};
template<>struct unsigned_cast<vbx_uhalf_t>{typedef vbx_uhalf_t type;};
template<>struct unsigned_cast<vbx_ubyte_t>{typedef vbx_ubyte_t type;};

template<typename T, int Dim>
Matrix<T,Dim> operator/( const Matrix<T,Dim>& N, const Matrix<T,Dim>& D)
{
	int size=N.get_size();
	Matrix<T,Dim> Q(size);
	Matrix<T,Dim> N_sign(size);
	Matrix<T,Dim> D_sign(size);
	int num_bits=sizeof(T)*8;
	typedef typename unsigned_cast<T>::type u_type;
	Matrix<u_type,Dim> uN(size);
	Matrix<u_type,Dim> uD(size);
	Matrix<u_type,Dim> uQ(size);
	Matrix<u_type,Dim> uR(size);
	Matrix<u_type,Dim> temp(size);
	uQ=uR=0;

	if(((T)-1)<0){//Signed type
		N_sign=1;
		N_sign.cond_set(N<0,-1);
		uN= N*N_sign;
		D_sign=1;
		D_sign.cond_set(D<0,-1);
		uD=D*D_sign;
		//if N== MIN(T) it will still be less than 0
		//set it to MAX(T)
		//eg for byte, -128 * -1 is still -128,
		//set it to 127
	}else{
		uN=N;
		uD=D;
	}

	while(num_bits--){
		uR<<=1;
		uR|=Bit(uN,num_bits);
		temp=0;
		temp.cond_set(uR>=uD,1<<num_bits);
		uR.cond_set(uR>=uD,uR-uD);
		uQ|=temp;
	}
	Q=uQ;
	if(((T)-1)<0){//Signed type
		//correct sign
		Q*=N_sign;
		Q*=D_sign;
	}
	return Q;
}
template<typename T, int Dim>
Matrix<T,Dim> operator/( const Matrix<T,Dim>& N,vbx_word_t D)
{
	Matrix<T,Dim>  d(N.get_size());
	d=D;
	return N/d;
}

template<typename T, int Dim>
Matrix<T,Dim> operator/( vbx_word_t N, const Matrix<T,Dim>& D)
{
	Matrix<T,Dim> n(D.get_size());
	n=N;
	return n/D;
}
template<typename T, int Dim>
Matrix<T,Dim> operator/( const Matrix<T,Dim>& N, struct Matrix<T,Dim>::Enumerated D)
{
	Matrix<T,Dim>	Denominator(N.get_size());
	Denominator.enumerate();
	return N/Denominator;
}

#undef MK_VV_OP
#define MK_VS_OP(OP,INST)	  \
	template<typename U, int D> \
	Matrix<U,D> operator OP (const Matrix<U,D> &lhs,vbx_word_t rhs) \
	{ \
		Matrix<U,D> temp(lhs.dimensions[0], \
		                 lhs.dimensions[1], \
		                 lhs.dimensions[2]); \
		vbxx_dim(D,INST,temp.data,rhs,lhs.data); \
		return temp; \
	} \
	  \
	template<typename U, int D> \
	Matrix<U,D> operator OP (vbx_word_t lhs,const Matrix<U,D>& rhs) \
	{ \
		return rhs OP lhs; \
	}
MK_VS_OP(+,VADD)
MK_VS_OP(*,VMUL)
MK_VS_OP(&,VAND)
MK_VS_OP(|,VOR)
MK_VS_OP(^,VXOR)
#undef MK_VS_OP
/**
 * Scalar operations hae some special cases:sub,shl,shr
 */
template<typename U, int D>
Matrix<U,D> operator - (const Matrix<U,D> &lhs,vbx_word_t rhs)
{
	Matrix<U,D> temp(lhs.dimensions[0],
	                 lhs.dimensions[1],
	                 lhs.dimensions[2]);
vbxx_dim(D,VADD,temp.data,-rhs,lhs.data);
	return temp;
}
template<typename U, int D>
Matrix<U,D> operator - (vbx_word_t lhs,const Matrix<U,D>& rhs)
{
	Matrix<U,D> temp(rhs.dimensions[0],
	                 rhs.dimensions[1],
	                 rhs.dimensions[2]);
	vbxx_dim(D,VSUB,temp.data,lhs,rhs.data);
	return temp;
}
template<typename U, int D>
Matrix<U,D> operator << (const Matrix<U,D> &lhs,vbx_word_t rhs)
{
	Matrix<U,D> temp(lhs.dimensions[0],
	                 lhs.dimensions[1],
	                 lhs.dimensions[2]);
	vbxx_dim(D,VSHL,temp.data,rhs,lhs.data);
	return temp;
}
template<typename U, int D>
Matrix<U,D> operator <<(vbx_word_t lhs,const Matrix<U,D>& rhs)
{
	Matrix<U,D> temp(rhs.dimensions[0],
	                 rhs.dimensions[1],
	                 rhs.dimensions[2]);

	vbxx_dim(D,VMOV,temp.data,lhs);
	vbxx_dim(D,VSHL,temp.data,rhs.data,temp.data);
	return temp;
}
template<typename U, int D>
Matrix<U,D> operator>>(const Matrix<U,D>& lhs,vbx_word_t rhs){
	Matrix<U,D> temp(lhs.dimensions[0],
	                 lhs.dimensions[1],
	                 lhs.dimensions[2]);
	/*do the vector math*/
	vbxx_dim(D,VSHR,temp.data,rhs,lhs.data);
	return temp;
}
template<typename U, int D>
Matrix<U,D> operator>>(vbx_word_t lhs,const Matrix<U,D>& rhs){
	Matrix<U,D> temp(rhs.dimensions[0],
	                 rhs.dimensions[1],
	                 rhs.dimensions[2]);

	/*do the vector math*/
	vbxx_dim(D,VMOV,temp.data,lhs);
	vbxx_dim(D,VSHR,temp.data,rhs.data,temp.data);

	return temp;
}

/*BEGIN COMPARISON OPERATOR*/
#define MK_COMP_OP( OP,type,reverse_type ,opposite_type,cond_mov)	  \
	template <typename T, int Dim> \
	struct  Matrix<T,Dim>:: type operator OP (const Matrix<T,Dim>& lhs,const Matrix<T,Dim>& rhs) \
	{ \
		struct Matrix<T,Dim>::type toRet(lhs.get_size()); \
		vbxx_dim(Dim,VSUB,toRet.vec.data,lhs.data,rhs.data); \
		return toRet; \
	} \
	  \
	template <typename T, int Dim> \
	struct Matrix<T,Dim>:: type operator OP (const vbx_word_t lhs,const Matrix<T,Dim>& rhs) \
	{ \
		struct Matrix<T,Dim>:: type toRet(rhs.get_size()); \
		vbxx_dim(Dim,VSUB,toRet.vec.data,lhs,rhs.data); \
		return toRet; \
	} \
	  \
	template <typename T, int Dim> \
	struct Matrix<T,Dim>:: reverse_type operator OP (const Matrix<T,Dim>& lhs,const vbx_word_t rhs) \
	{ \
		struct Matrix<T,Dim>:: reverse_type toRet(lhs.get_size()); \
		vbxx_dim(Dim,VSUB,toRet.vec.data,rhs,lhs.data); \
		return toRet; \
	} \
	template <typename T, int Dim> \
	struct Matrix<T,Dim>:: opposite_type Matrix<T,Dim>:: type ::operator!( ) \
	{ \
		struct opposite_type* toRet=(opposite_type*)this;\
		return *toRet; \
	} \
	template<typename T, int Dim> \
	Matrix<T,Dim>& Matrix<T,Dim>::cond_set(const type & predicate,const Matrix& new_data) \
	{ \
		vbxx_dim(Dim, cond_mov ,this->data,new_data.data,predicate.vec.data); \
		return *this; \
	} \
	template<typename T, int Dim> \
	Matrix<T,Dim>& Matrix<T,Dim>::cond_set(const type & predicate,const vbx_word_t new_data) \
	{ \
		vbxx_dim(Dim, cond_mov ,this->data,new_data,predicate.vec.data); \
		return *this; \
	}
MK_COMP_OP(>,Comp_GT  , Comp_LT, Comp_LEQ ,VCMV_GTZ)
MK_COMP_OP(<,Comp_LT  , Comp_GT, Comp_GEQ ,VCMV_LTZ)
MK_COMP_OP(>=,Comp_GEQ, Comp_LEQ,Comp_LT  ,VCMV_GEZ)
MK_COMP_OP(<=,Comp_LEQ, Comp_GEQ,Comp_GT  ,VCMV_LEZ)
MK_COMP_OP(==,Comp_EQU, Comp_EQU,Comp_NEQ ,VCMV_Z)
MK_COMP_OP(!=,Comp_NEQ, Comp_NEQ,Comp_EQU ,VCMV_NZ)

template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::cond_set(const Matrix<T,Dim>& predicate,const Matrix<T,Dim>& new_data)
{
	vbxx_dim(Dim,VCMV_NZ,this->data,new_data.data,predicate.data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::cond_set(const Matrix<T,Dim>& predicate,const vbx_word_t new_data)
{
	vbxx_dim(Dim,VCMV_NZ,this->data,new_data,predicate.data);
	return *this;
}
template<typename T, int Dim>
struct  Matrix<T,Dim>::Comp_EQU Matrix<T,Dim>::operator!()
{
	Comp_EQU toRet;
	toRet.vec.shallow_copy(this);
	return toRet;
}

//END COMPARISON OPERATIONS

template<typename T, int Dim>
Matrix<T,Dim> Matrix<T,Dim>::operator~(){
	return *this ^(~0);
}

template<typename T, int Dim>
Matrix<T,Dim> Matrix<T,Dim>::operator+(){
	return *this ;
}

template<typename T, int Dim>
Matrix<T,Dim> Matrix<T,Dim>::operator-(){
	return *this * -1;
}

template<typename T, int Dim>
Matrix<T,Dim> Matrix<T,Dim>::operator++(){
	return *this +1;
}

template<typename T, int Dim>
Matrix<T,Dim> Matrix<T,Dim>::operator--(){
	return *this -1;
}

template<typename T, int Dim>
Matrix<T,Dim> Matrix<T,Dim>::operator++(int ){
	Matrix temp(this->data_size);
	temp=*this ;
	++this;
	return temp;
}
template<typename T, int Dim>
Matrix<T,Dim> Matrix<T,Dim>::operator--(int ){
	Matrix temp(this->data_size);
	temp=*this ;
	--this;
	return temp;
}

/*compound assignment operators*/
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator+=(const Matrix<T,Dim>& lhs )
{
	vbxx_dim(Dim,VADD,this->data,this->data,lhs.data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator-=(const Matrix<T,Dim> &lhs )
{
	vbxx_dim(Dim,VSUB,this->data,this->data,lhs.data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator*=(const Matrix<T,Dim> &lhs )
{
	vbxx_dim(Dim,VMUL,this->data,this->data,lhs.data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator&=(const Matrix<T,Dim> &lhs )
{
	vbxx_dim(Dim,VAND,this->data,this->data,lhs.data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator|=(const Matrix<T,Dim> &lhs )
{
	vbxx_dim(Dim,VOR,this->data,this->data,lhs.data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator^=(const Matrix<T,Dim> &lhs )
{
	vbxx_dim(Dim,VXOR,this->data,this->data,lhs.data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator<<=(const Matrix<T,Dim> &lhs )
{
	vbxx_dim(Dim,VSHL,this->data,lhs.data,this->data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator>>=(const Matrix<T,Dim> &lhs )
{
	vbxx_dim(Dim,VSHR,this->data,lhs.data,this->data);
	return *this;
}

template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator+=(vbx_word_t lhs )
{
	vbxx_dim(Dim,VADD,this->data,lhs,this->data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator-=(vbx_word_t lhs )
{
	vbxx_dim(Dim,VADD,this->data,-lhs,this->data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator*=(vbx_word_t lhs )
{
	vbxx_dim(Dim,VMUL,this->data,lhs,this->data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator&=(vbx_word_t lhs )
{
	vbxx_dim(Dim,VAND,this->data,lhs,this->data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator|=(vbx_word_t lhs )
{
	vbxx_dim(Dim,VOR,this->data,lhs,this->data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator^=(vbx_word_t lhs )
{
	vbxx_dim(Dim,VXOR,this->data,lhs,this->data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator<<=(vbx_word_t lhs )
{
	vbxx_dim(Dim,VSHL,this->data,lhs,this->data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::operator>>=(vbx_word_t lhs )
{
	vbxx_dim(Dim,VSHR,this->data,lhs,this->data);
	return *this;
}
template<typename T, int Dim>
Matrix<T,Dim>& Matrix<T,Dim>::enumerate( vbx_word_t N)
{
	vbxx_dim(Dim,VMUL,this->data,N,(vbx_enum_t*)0);
	return *this;
}

//Used by accumulate method
template<class T>
struct word_size;
template<>struct word_size<vbx_word_t>{typedef vbx_word_t type;};
template<>struct word_size<vbx_half_t>{typedef vbx_word_t type;};
template<>struct word_size<vbx_byte_t>{typedef vbx_word_t type;};
template<>struct word_size<vbx_uword_t>{typedef vbx_uword_t type;};
template<>struct word_size<vbx_uhalf_t>{typedef vbx_uword_t type;};
template<>struct word_size<vbx_ubyte_t>{typedef vbx_uword_t type;};

template<typename T>
class Matrix<T,0>{
public:

	Matrix(int,int,int)
		:data((vbx_word_t*)vbx_sp_malloc(sizeof(*data)))
	{}
	vbx_word_t* data;
	vbx_word_t* get_data(){return *data;}
	vbx_word_t* get_sp_ptr(){return data;}
	int get_dimensions(int){return 1;}
	int get_size(){return 1;}
	void printVec() const {vbx_sync();printf("[0]=%X\n",(unsigned)*data);}
};

template<typename T, int Dim>
Matrix<T,Dim-1> Matrix<T,Dim>::accumulate()
{
	//if Dim=1, this will access memory from
	//dimensions[-1],this is ok, because
	//the Matrix<T,0> constructor ignores the
	//size parameter
	typedef typename word_size<T>::type wT;
	int dest_dim[]={1,1,1};
	for(int i=0;i<Dim;i++){
		dest_dim[i]=this->dimensions[i];
	}

	Matrix<T,Dim-1>dest(dest_dim[0],dest_dim[1],dest_dim[2]);
	vbxx_acc_dim(Dim,VMUL,(wT*)(dest.data),(T)1,this->data);
	return dest;
}
template<typename T,int Dim>
inline int Matrix<T,Dim>::get_size()const
{
	int ret=1;
	switch(Dim){
	case 3:
		ret*=this->dimensions[2];
	case 2:
		ret*=this->dimensions[1];
	case 1:
		ret*=this->dimensions[0];
	}
	return ret;
}
template<typename T, int Dim>
void Matrix<T,Dim>::get_data(T* buffer) const
{
	vbx_dma_to_host(buffer,this->data,this->get_size()*sizeof(*(this->data)));
}
template<typename T, int Dim>
void Matrix<T,Dim>::set_data(void* buffer)
{
	//flush if it is not an uncached pointer
	if (buffer!=vbx_remap_uncached(buffer)){
		vbx_dcache_flush(buffer,get_size()*sizeof(*data));
	}
	vbx_dma_to_vector(data,buffer,get_size()*sizeof(*data));
}



template<typename T, int Dim>
struct Matrix<T,Dim>::Comp_FS Matrix<T,Dim>::underflow()
{
	Comp_LT temp(this->dimensions[0],this->dimensions[1],this->dimensions[2]);
	temp.vec=*this;
	return temp;
}
template<typename T, int Dim>
struct Matrix<T,Dim>::Comp_FS Matrix<T,Dim>::overflow()
{
	Comp_LT temp(this->dimensions[0],this->dimensions[1],this->dimensions[2]);
	temp.vec=*this;
	return temp;
}
template<typename T, int Dim>
struct Matrix<T,Dim>::Comp_FC Matrix<T,Dim>::flag_clear()
{
	Comp_GEQ temp(this->dimensions[0],this->dimensions[1],this->dimensions[2]);
	temp.vec=*this;
	return temp;
}
#endif
