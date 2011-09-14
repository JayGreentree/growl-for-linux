#ifndef plugins_from_url_h_
#define plugins_from_url_h_

#include <stddef.h>

#include <glib.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#include <curl/curl.h>

#include "memfile.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    const char* url;
    MEMFILE**   body;
    MEMFILE**   header;
    size_t (*body_writer)(const char*, size_t, size_t, void*);
    size_t (*header_writer)(const char*, size_t, size_t, void*);
} memfile_from_url_info;

// *body* and *header* field are not modified when error.
CURLcode
memfile_from_url(memfile_from_url_info);

GdkPixbuf*
pixbuf_from_url(const char*, GError**);

#ifdef __cplusplus
}
#endif

#endif /* plugins_from_url_h_ */

