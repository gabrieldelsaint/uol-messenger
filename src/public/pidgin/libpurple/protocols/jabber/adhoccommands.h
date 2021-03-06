/*
 * purple - Jabber Protocol Plugin
 *
 * Copyright (C) 2007, Andreas Monitzer <andy@monitzer.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA	 02111-1307	 USA
 *
 */

#ifndef _PURPLE_JABBER_ADHOCCOMMANDS_H_
#define _PURPLE_JABBER_ADHOCCOMMANDS_H_

#include "jabber.h"

/* Implementation of XEP-0050 */

void jabber_adhoc_disco_result_cb(JabberStream *js, xmlnode *packet, gpointer data);

void jabber_adhoc_execute(JabberStream *js, JabberAdHocCommands *cmd);

void jabber_adhoc_execute_action(PurpleBlistNode *node, gpointer data);

void jabber_adhoc_server_get_list(JabberStream *js);

void jabber_adhoc_init_server_commands(JabberStream *js, GList **m);

#endif /* _PURPLE_JABBER_ADHOCCOMMANDS_H_ */
