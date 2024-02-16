// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Copyright (C) 2021-2024 by Agustin Alvarez. All rights reserved.
//
// This work is licensed under the terms of the MIT license.
//
// For a copy, see <https://opensource.org/licenses/MIT>.
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#pragma once

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [  HEADER  ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include "Core/Serialization/Binary/COM_Reader.hpp"
#include "Core/Serialization/Binary/COM_Writer.hpp"
#include "COM_Protocol.hpp"
#include <Network/Server.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace COM
{
    // -=(Undocumented)=-
    [object, uuid("70DADE73-C941-11EE-ADEA-1418C3A8EDB8"), pointer_default(unique)]
    __interface Network_Server_
    {
        HRESULT SetProtocol([in] Network_Protocol_ * Protocol);

        HRESULT Disconnect([in] vbBool Forcibly);

        HRESULT Broadcast([in] BinaryWriter_ * Message);

        HRESULT Flush();
    };

    // -=(Undocumented)=-
    [coclass, uuid("7657C303-C941-11EE-ADEA-1418C3A8EDB8")]
    class ATL_NO_VTABLE Network_Server : public Network_Server_, public CSmartPtrWrapper<Network::Server>
    {
    public:

        // \see Network_Server_::SetProtocol
        HRESULT SetProtocol(Network_Protocol_ * Protocol) override;

        // \see Network_Server_::Disconnect
        HRESULT Disconnect(vbBool Forcibly) override;

        // \see Network_Server_::Broadcast
        HRESULT Broadcast(BinaryWriter_ * Message) override;

        // \see Network_Server_::Flush
        HRESULT Flush() override;
    };
}