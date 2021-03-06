/* UOL Messenger
 * Copyright (c) 2005 Universo Online S/A
 *
 * Direitos Autorais Reservados
 * All rights reserved
 *
 * Este programa � software livre; voc� pode redistribu�-lo e/ou modific�-lo
 * sob os termos da Licen�a P�blica Geral GNU conforme publicada pela Free
 * Software Foundation; tanto a vers�o 2 da Licen�a, como (a seu crit�rio)
 * qualquer vers�o posterior.
 * Este programa � distribu�do na expectativa de que seja �til, por�m,
 * SEM NENHUMA GARANTIA; nem mesmo a garantia impl�cita de COMERCIABILIDADE
 * OU ADEQUA��O A UMA FINALIDADE ESPEC�FICA. Consulte a Licen�a P�blica Geral
 * do GNU para mais detalhes. 
 * Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral do GNU junto
 * com este programa; se n�o, escreva para a Free Software Foundation, Inc.,
 * no endere�o 59 Temple Street, Suite 330, Boston, MA 02111-1307 USA. 
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Universo Online S/A - A/C: UOL Messenger 5o. Andar
 * Avenida Brigadeiro Faria Lima, 1.384 - Jardim Paulistano
 * S�o Paulo SP - CEP 01452-002 - BRASIL  */
 
#pragma once

class IUOLMessengerProtocolManager;
MAKEAUTOPTR(IUOLMessengerProtocolManager);

#include "IUOLMessengerAccountManager.h"
#include "../../protocols/improtocol.h"

class __declspec(novtable) IUOLMessengerProtocolManager
{
public:
	virtual ~IUOLMessengerProtocolManager(void) { }

	virtual void GetProtocolList(CConstAtlListIterator< CIMProtocol* >& itProtocols) = 0;
	virtual CIMProtocol* GetProtocol(const CString& strProtocolId) = 0;

	virtual BOOL AddProtocolToStack(const CString& strProtocolId, CIMProtocol* pProtocol, CIMProtocolCallback* pCallback) = 0;
	virtual BOOL RemoveProtocolFromStack(const CString& strProtocolId, CIMProtocol* pProtocol, CIMProtocolCallback* pCallback) = 0;
};


class __declspec(novtable) IUOLMessengerProtocolManager2 : public IUOLMessengerProtocolManager
{
public:
	virtual ~IUOLMessengerProtocolManager2(void) { }
	
	virtual CIMProtocol* GetProtocol(const CString& strProtocolId, const CString& strUserId) = 0;
};

MAKEAUTOPTR(IUOLMessengerProtocolManager2);


class __declspec(novtable) IUOLMessengerProtocolManager3 : public IUOLMessengerProtocolManager2
{
public:
	
	enum ProtocolId
	{
		PROTOCOL_ID_ICQ			= 1,
		PROTOCOL_ID_JABBER		= 2,
		PROTOCOL_ID_MSN			= 4,
		PROTOCOL_ID_UOL			= 8,
		PROTOCOL_ID_TODAOFERTA	= 16,
		PROTOCOL_ID_YAHOO		= 32
	};
	
public:
	virtual ~IUOLMessengerProtocolManager3(void) { }
	
	virtual CString GetProtocolStrId(ProtocolId nProtocolId) = 0;
};

MAKEAUTOPTR(IUOLMessengerProtocolManager3);

