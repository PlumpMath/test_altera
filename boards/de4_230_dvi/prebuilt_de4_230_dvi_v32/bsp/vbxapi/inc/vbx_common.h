/**
 * @file
 * @defgroup vbx_common
 * @brief vbx common
 *
 * @ingroup vbxapi
 */
/**@{*/
//VBXCOPYRIGHTTAG

#ifndef __VBX_COMMON_H
#define __VBX_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef min

/** Macro returning min of two inputs
 *
 * @param[in] x
 * @param[in] y
 * @retval returns minimum of x and y
 */
#define min(x,y) \
	({\
		typeof(x) __x__ = (x);\
		typeof(y) __y__ = (y);\
		(__x__<__y__)? __x__ : __y__;\
	})
#endif // min()

#ifndef max

/** Macro returning max of two inputs
 *
 * @param[in] x
 * @param[in] y
 * @retval returns maximum of x and y
 */
#define max(x,y) \
	({\
		typeof(x) __x__ = (x);\
		typeof(y) __y__ = (y);\
		(__x__>__y__)? __x__ : __y__;\
	})
#endif // max()



#ifdef __cplusplus
}
#endif

#endif // __VBX_COMMON_H
/**@}*/
