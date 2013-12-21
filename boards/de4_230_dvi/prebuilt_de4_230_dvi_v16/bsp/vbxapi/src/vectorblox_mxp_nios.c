/**@file*/
//VBXCOPYRIGHTTAG

#include "vbx_copyright.h"
VBXCOPYRIGHT( vectorblox_mxp )

#include "vbx.h"
#include "vectorblox_mxp.h"

#include "sys/alt_errno.h"
#include "priv/alt_file.h"


ALT_LLIST_HEAD( vbx_mxp_list );


vbx_mxp_t *vbx_open( const char* name )
{
	vbx_mxp_dev_t *dev;
	dev = (vbx_mxp_dev_t *)alt_find_dev( name, &vbx_mxp_list );
	if( !dev ) {
		ALT_ERRNO = ENODEV;
	}
	return &(dev->mxp);
}


void _vectorblox_mxp_init( vbx_mxp_dev_t *dev )
{
	/* register this MXP instance with the HAL */
	alt_llist_insert( &vbx_mxp_list, &dev->llist );
	_vbx_init( &(dev->mxp) );
}


