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

/**
 * @file
 * @defgroup VBX_Vector Vector class operationss
 * @brief Define Vector operations
 *
 * @ingroup VBXapi
 *
 * ####Includes
 * * @ref vbx.h
 *
 */


#ifndef __VBX_VECTOR_HPP
#define __VBX_VECTOR_HPP
#include "vbx.h"
namespace VBX{


	/**
	 * \brief This class is designed to make doing Vector Operations
	 * very easy.Operators return a temporary vector containing the result
	 * of the calculation. If one of the operands is a temporary vector,
	 * the returned vector will reuse that vector's scratchpad space.
	 * For instance the expression a+b+c*d will create allocate 2
	 * tempary buffers on the scratchpad, whereas a+b+c+d will allocate
	 * just one buffer
	 */
	template<class T,int Dim>
	class Matrix {
		template<typename U,int D>
		friend class Matrix;
		int dimensions[3];
		T* data;
		struct Enumerated{
		};
	public:
		struct Comp_LT ;
		struct Comp_GT ;
		struct Comp_LEQ;
		struct Comp_GEQ;
		struct Comp_EQU;
		struct Comp_NEQ;
		struct Comp_LT{
			Matrix<T,Dim> vec;
			struct Comp_GEQ operator!();
			Comp_LT(int sz):vec(sz){}
		};
		struct Comp_GT{
			Matrix<T,Dim> vec;
			struct Comp_LEQ operator!();
			Comp_GT(int sz):vec(sz){}
		};
		struct Comp_LEQ{
			Matrix<T,Dim> vec;
			struct Comp_GT operator!();
			Comp_LEQ(int sz):vec(sz){}
		};
		struct Comp_GEQ{
			Matrix<T,Dim> vec;
			struct Comp_LT operator!();
			Comp_GEQ(int sz):vec(sz){}
		};
		struct Comp_EQU{
			Matrix<T,Dim> vec;
			struct Comp_NEQ operator!();
			Comp_EQU(int sz):vec(sz){}
		};
		struct Comp_NEQ{
			Matrix<T,Dim> vec;
			struct Comp_EQU operator!();
			Comp_NEQ(int sz):vec(sz){}
		};
		typedef Comp_LT Comp_FS;
		typedef Comp_GEQ Comp_FC;
		static Enumerated ENUM;
		~Matrix();
		/**
		 * @brief Copy constructor
		 * This does a deep copy.
		 *
		 * @param cp Matrix to be copied
		 */
		Matrix(const Matrix<T,Dim>& cp);
		/**
		 * Cross copy constructor
		 * Deep copy for type conversion
		 * #param cp Matrix to be copied
		 */
		template<typename U,int D>
		Matrix(const Matrix<U,D>& cp);
		/**
		 * Create a vector with @em size  elements
		 *
		 * @param size_d1 size of matrix in the first dimension
		 * @param size_d2 size of matrix in the second dimension
		 * @param size_d3 size of matrix in the third dimension
		 */

		Matrix(int size_d1,int size_d2=1,int size_d3=1);

		///\name Assignment
		/// \{

		/**
		 * Assign scalar to vector
		 *
		 * \returns *this
		 */
		Matrix & operator=(vbx_word_t K);
		/**
		 * Assignment operator
		 * copy data from  `cp` to this
		 * @param cp vector to be copied
		 *
		 * @return *this
		 */
		Matrix& operator=(const Matrix<T,Dim>& cp);
		/**
		 * Cross type Assignment operator,
		 * Allows Assigning from Matrix<word> to Matrix<half> and visa versa
		 * Note: Does not allow assigning from unsigned to signed
		 * @param cp
		 *
		 * @return *this
		 */
		template<typename U,int D>
		Matrix<T,Dim>& operator=(const Matrix<U,D>& cp);
		///\}
		/**
		 * @brief Conditional assignment<br>
		 * Assign @em new_data to @em *this if @em predicate is true<br>
		 * <code><br>
		 * vector<vbx_word_t> va(10),vb(10),vc(10);<br>
		 * va.cond_set(va<vb,vc);<br>
		 * </code>

		 * Is equivalent to<br>
		 * <code>
		 * int a,b,c;<br>
		 * if(a<b) a=c;<br>
		 * </code>
		 * @param predicate
		 * @param new_data
		 *
		 * @return *this
		 */
		Matrix& cond_set(const Comp_GT& predicate,const Matrix& new_data);
		Matrix& cond_set(const Comp_LT& predicate,const Matrix& new_data);
		Matrix& cond_set(const Comp_GEQ& predicate,const Matrix& new_data);
		Matrix& cond_set(const Comp_LEQ& predicate,const Matrix& new_data);
		Matrix& cond_set(const Comp_EQU& predicate,const Matrix& new_data);
		Matrix& cond_set(const Comp_NEQ& predicate,const Matrix& new_data);
		Matrix& cond_set(const Matrix& predicate,const Matrix& new_data);
		Matrix& cond_set(const Comp_GT& predicate ,const vbx_word_t new_data);
		Matrix& cond_set(const Comp_LT& predicate ,const vbx_word_t new_data);
		Matrix& cond_set(const Comp_GEQ& predicate,const vbx_word_t new_data);
		Matrix& cond_set(const Comp_LEQ& predicate,const vbx_word_t new_data);
		Matrix& cond_set(const Comp_EQU& predicate,const vbx_word_t new_data);
		Matrix& cond_set(const Comp_NEQ& predicate,const vbx_word_t new_data);
		Matrix& cond_set(const Matrix& predicate  ,const vbx_word_t new_data);

		/**
		 * Accessor to get scratchpad pointer,
		 * usefull if you want to use vbxx() calls with it
		 *
		 * \returns pointer to scratchpad data help by this Matrix
		 */
		T* get_sp_ptr() const {return this->data;}
		/**
		 *Accessor to get the size of the Matrix
		 *
		 * \returns size of vector
		 */
		int get_size() const;
		/**
		 * Get data from scratchpad, and move it into
		 * the buffer pointed to by \em buffer
		 *
		 * \param buffer pointer to move data to
		 */
		void get_data (T* buffer)const ;
		/**
		 * Move the data from memory pointed to by \em buffer
		 * into scratchpad memory held by this Matrix
		 *
		 * \Param pointer to data to be moved into scratchpad
		 */
		void set_data(void* buffer);

		/**
		 * Fill this vector with 1N,2N,3N, ...\ N*(this->data_size)
		 *
		 * @returns *this
		 */
		Matrix& enumerate( vbx_word_t N=1);
		/**
		 * Accumulate the vector.
		 * \Param sync If true, the function ins syncronous
		 * \returns The sum of all the elements in the vector
		 */
		Matrix<T,Dim-1> accumulate();
		/**
		 *
		 * \param get size of matrix in the nth dimension n=1,2or3
		 * \returns the size of the vector in the nth dimension
		 */
		int get_dimensions(int n){return dimensions[Dim-1];}
		//define friends for all vector to vector operations
		/**
		 * \name Overloaded Operators
		 */
		/**@{*/
		template<typename U,int D>	friend Matrix<U,D> operator+ (const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>	friend Matrix<U,D> operator- (const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>	friend Matrix<U,D> operator* (const Matrix<U,D>&,const Matrix<U,D>&);
		//not using references, because we modify the arguments in the function
		template<typename U,int D>	friend Matrix<U,D> operator/ (const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>	friend Matrix<U,D> operator& (const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>	friend Matrix<U,D> operator| (const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>	friend Matrix<U,D> operator^ (const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>	friend Matrix<U,D> operator<<(const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>	friend Matrix<U,D> operator>>(const Matrix<U,D>&,const Matrix<U,D>&);

		//scalar versions
		template<typename U,int D>	friend Matrix<U,D> operator+(const Matrix<U,D>&, vbx_word_t );
		template<typename U,int D>	friend Matrix<U,D> operator+(vbx_word_t,const Matrix<U,D>&  );
		template<typename U,int D>	friend Matrix<U,D> operator-(const Matrix<U,D>&, vbx_word_t );
		template<typename U,int D>	friend Matrix<U,D> operator-(vbx_word_t,const Matrix<U,D>&  );
		template<typename U,int D>	friend Matrix<U,D> operator*(const Matrix<U,D>&, vbx_word_t );
		template<typename U,int D>	friend Matrix<U,D> operator*(vbx_word_t,const Matrix<U,D>&  );
		template<typename U,int D>	friend Matrix<U,D> operator/(const Matrix<U,D>&, vbx_word_t );
		template<typename U,int D>	friend Matrix<U,D> operator/(vbx_word_t,const Matrix<U,D>&  );
		template<typename U,int D>	friend Matrix<U,D> operator&(const Matrix<U,D>&, vbx_word_t  );
		template<typename U,int D>	friend Matrix<U,D> operator&(vbx_word_t,const Matrix<U,D>&   );
		template<typename U,int D>	friend Matrix<U,D> operator|(const Matrix<U,D>&, vbx_word_t  );
		template<typename U,int D>	friend Matrix<U,D> operator|(vbx_word_t,const Matrix<U,D>&   );
		template<typename U,int D>	friend Matrix<U,D> operator^(const Matrix<U,D>&, vbx_word_t  );
		template<typename U,int D>	friend Matrix<U,D> operator^(vbx_word_t,const Matrix<U,D>&   );
		template<typename U,int D>	friend Matrix<U,D> operator<<(const Matrix<U,D>&, vbx_word_t );
		template<typename U,int D>	friend Matrix<U,D> operator<<(vbx_word_t,const Matrix<U,D>&  );
		template<typename U,int D>	friend Matrix<U,D> operator>>(const Matrix<U,D>&, vbx_word_t );
		template<typename U,int D> friend Matrix<U,D> operator>>(vbx_word_t,const Matrix<U,D>&  );

		/// \name Enumerated operators
		/// \brief the right hand side operator is a vector from 1,2,...size-1,size
		/// using these is slightly more efficient;
		/// \{
		template<typename U,int D>	friend Matrix<U,D> operator+(const Matrix<U,D>&,const struct Matrix<U,D>::Enumerated  );
		template<typename U,int D>	friend Matrix<U,D> operator-(const Matrix<U,D>&,const struct Matrix<U,D>::Enumerated  );
		template<typename U,int D>	friend Matrix<U,D> operator*(const Matrix<U,D>&,const struct Matrix<U,D>::Enumerated  );
		template<typename U,int D>	friend Matrix<U,D> operator/(const Matrix<U,D>&,const struct Matrix<U,D>::Enumerated  );
		template<typename U,int D>	friend Matrix<U,D> operator&(const Matrix<U,D>&,const struct Matrix<U,D>::Enumerated  );
		template<typename U,int D>	friend Matrix<U,D> operator|(const Matrix<U,D>&,const struct Matrix<U,D>::Enumerated  );
		template<typename U,int D>	friend Matrix<U,D> operator^(const Matrix<U,D>&,const struct Matrix<U,D>::Enumerated  );
		/// \}
		/// \name Comparison Operators
		/// \{
		///
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_GT operator>(const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_LT operator>(const Matrix<U,D>&,const vbx_word_t);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_GT operator>(const vbx_word_t,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_LT operator<(const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_GT operator<(const Matrix<U,D>&,const vbx_word_t);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_LT operator<(const vbx_word_t,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_GEQ operator>=(const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_LEQ operator>=(const Matrix<U,D>&,const vbx_word_t);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_GEQ operator>=(const vbx_word_t,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_LEQ operator<=(const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_GEQ operator<=(const Matrix<U,D>&,const vbx_word_t);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_LEQ operator<=(const vbx_word_t,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_EQU operator==(const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_EQU operator==(const Matrix<U,D>&,const vbx_word_t);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_EQU operator==(const vbx_word_t,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_NEQ operator!=(const Matrix<U,D>&,const Matrix<U,D>&);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_NEQ operator!=(const Matrix<U,D>&,const vbx_word_t);
		template<typename U,int D>
		friend struct Matrix<U,D>::Comp_NEQ operator!=(const vbx_word_t,const Matrix<U,D>&);
		/// \}
		Comp_FS underflow();
		Comp_FS overflow();
		Comp_FC flag_clear();
		/** \name Unary Operators*/
		/// \{
		Comp_EQU operator! ();
		///bitwise not
		Matrix operator~ ();
		///unary + operator
		Matrix operator+ ();
		///negation operator
		Matrix operator- ();
		///prefix increment
		Matrix operator++();
		///prefix decrement
		Matrix operator--();
		///postfix increment
		Matrix operator++(int );/*postfix*/
		///postfix decrement
		Matrix operator--(int );/*postfix*/
		/// \}
		/**\name Compound Assignmnent*/
		///\{
		Matrix& operator+= (const Matrix &);
		Matrix& operator-= (const Matrix &);
		Matrix& operator*= (const Matrix &);
		Matrix& operator&= (const Matrix &);
		Matrix& operator|= (const Matrix &);
		Matrix& operator^= (const Matrix &);
		Matrix& operator<<=(const Matrix &);
		Matrix& operator>>=(const Matrix &);
		Matrix& operator+= (vbx_word_t);
		Matrix& operator-= (vbx_word_t);
		Matrix& operator*= (vbx_word_t);
		Matrix& operator&= (vbx_word_t);
		Matrix& operator|= (vbx_word_t);
		Matrix& operator^= (vbx_word_t);
		Matrix& operator<<=(vbx_word_t);
		Matrix& operator>>=(vbx_word_t);
		///\}

		void  printVec(int N=-1) const{
			vbx_sync();
			if (N!=-1){
				printf("[%d]=%08X\n",N,(unsigned)data[N]);
				return;
			}
			for(int i=0;i<this->get_size();i++){
				printf("[%d]=%08X\n",i,(unsigned)data[i]);
			}
		}
	};
	/*template class, so the implementation must be included everytime*/
#include "vbx_vector_implementation.hpp"
}
#endif //__VBX_VECTOR_HPP
