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
#include <Network/Client.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace COM
{
    // -=(Undocumented)=-
    [object, uuid("59C3336C-C941-11EE-ADEA-1418C3A8EDB8"), pointer_default(unique)]
    __interface Network_Client_
    {
        HRESULT Attach([in] Network_Protocol_ * Protocol);

        HRESULT Close([in] vbBool Forcibly);

        HRESULT Write([in] BinaryWriter_ * Message);

        HRESULT Flush();
    };

    // -=(Undocumented)=-
    [coclass, uuid("5D181B42-C941-11EE-ADEA-1418C3A8EDB8")]
    class ATL_NO_VTABLE Network_Client : public Network_Client_, public CSmartPtrWrapper<Network::Client>
    {
    public:

        // \see Network_Client_::Attach
        HRESULT Attach(Network_Protocol_ * Protocol) override;

        // \see Network_Client_::Close
        HRESULT Close(vbBool Forcibly) override;

        // \see Network_Client_::Write
        HRESULT Write(BinaryWriter_ * Message) override;

        // \see Network_Client_::Flush
        HRESULT Flush() override;
    };
}