/* Icecast
 *
 * This program is distributed under the GNU General Public License, version 2.
 * A copy of this license is included with this source.
 *
 * Copyright 2000-2004, Jack Moffitt <jack@xiph.org, 
 *                      Michael Smith <msmith@xiph.org>,
 *                      oddsock <oddsock@xiph.org>,
 *                      Karl Heyes <karl@xiph.org>
 *                      and others (see AUTHORS for details).
 */

/* client.h
**
** client data structions and function definitions
**
*/
#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "connection.h"
#include "refbuf.h"
#include "httpp/httpp.h"

typedef struct _client_tag
{
    /* the client's connection */
    connection_t *con;
    /* the client's http headers */
    http_parser_t *parser;

    /* http response code for this client */
    int respcode;

    /* where in the queue the client is */
    refbuf_t *refbuf;

    /* position in first buffer */
    unsigned long pos;

    /* Client username, if authenticated */
    char *username;

    /* Format-handler-specific data for this client */
  void * E_OPAQUE format_data; /**DSU xfgen */

    /* function to call to release format specific resources */
    void (*free_client_data)(struct _client_tag *client);
} client_t;

client_t *client_create(connection_t *con, http_parser_t *parser);
void client_destroy(client_t *client);
void client_send_504(client_t *client, char *message);
void client_send_404(client_t *client, char *message);
void client_send_401(client_t *client);
void client_send_403(client_t *client);
void client_send_400(client_t *client, char *message);
int client_send_bytes (client_t *client, const void *buf, unsigned len);
void client_set_queue (client_t *client, refbuf_t *refbuf);

#endif  /* __CLIENT_H__ */
