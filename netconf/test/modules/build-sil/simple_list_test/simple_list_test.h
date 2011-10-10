
#ifndef _H_simple_list_test
#define _H_simple_list_test
/* 

 * Copyright (c) 2009 - 2011, Andy Bierman
 * All Rights Reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *

*** Generated by yangdump 2.1.1471:1477

    Combined SIL header
    module simple_list_test
    revision 2008-11-20
    namespace http://netconfcentral.org/ns/simple_list_test

 */

#include <xmlstring.h>

#include "dlq.h"
#include "ncxtypes.h"
#include "op.h"
#include "status.h"
#include "val.h"

#ifdef __cplusplus
extern "C" {
#endif

#define y_simple_list_test_M_simple_list_test (const xmlChar *)"simple_list_test"
#define y_simple_list_test_R_simple_list_test (const xmlChar *)"2008-11-20"

#define y_simple_list_test_N_simple_list (const xmlChar *)"simple_list"
#define y_simple_list_test_N_theKey (const xmlChar *)"theKey"
#define y_simple_list_test_N_theList (const xmlChar *)"theList"
#define y_simple_list_test_N_theVal (const xmlChar *)"theVal"

/* list /simple_list/theList */
typedef struct y_simple_list_test_T_simple_list_theList_ {
    dlq_hdr_t qhdr;
    xmlChar *theKey;
    xmlChar *theVal;
} y_simple_list_test_T_simple_list_theList;

/* container /simple_list */
typedef struct y_simple_list_test_T_simple_list_ {
    dlq_hdr_t theList;
} y_simple_list_test_T_simple_list;

/********************************************************************
* FUNCTION y_simple_list_test_init
* 
* initialize the simple_list_test server instrumentation library
* 
* INPUTS:
*    modname == requested module name
*    revision == requested version (NULL for any)
* 
* RETURNS:
*     error status
********************************************************************/
extern status_t y_simple_list_test_init (
    const xmlChar *modname,
    const xmlChar *revision);


/********************************************************************
* FUNCTION y_simple_list_test_init2
* 
* SIL init phase 2: non-config data structures
* Called after running config is loaded
* 
* RETURNS:
*     error status
********************************************************************/
extern status_t y_simple_list_test_init2 (void);


/********************************************************************
* FUNCTION y_simple_list_test_cleanup
*    cleanup the server instrumentation library
* 
********************************************************************/
extern void y_simple_list_test_cleanup (void);

#ifdef __cplusplus
} /* end extern 'C' */
#endif

#endif