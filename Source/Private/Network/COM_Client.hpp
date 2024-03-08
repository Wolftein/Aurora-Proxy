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
#include "COM_Statistics.hpp"
#include <Network/Client.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace COM
{
    // -=(Undocumented)=-
    [export, uuid("50585AA2-0027-41A8-9D94-963E499D255F"), v1_enum]
    typedef enum Network_Channel
    {
        eChannelReliable,
        eChannelUnreliable,
        eChannelUnsequenced,
    } Network_Channel;

    // -=(Undocumented)=-
    [object, uuid("59C3336C-C941-11EE-ADEA-1418C3A8EDB8"), pointer_default(unique)]
    __interface Network_Client_
    {
        HRESULT SetAttachment([in] vbInt32 Attachment);

        HRESULT GetAttachment([out, retval] vbInt32 * Result);

        HRESULT SetProtocol([in] Network_Protocol_ * Protocol);

        HRESULT Poll();

        HRESULT Flush();

        HRESULT Close([in] vbBool Forcibly);

        HRESULT Write([in] BinaryWriter_ * Message, [in, defaultvalue(0)] Network_Channel Mode);

        HRESULT GetStatistics([out, retval] Network_Statistics * Result);
    };

    // -=(Undocumented)=-
    [coclass, uuid("5D181B42-C941-11EE-ADEA-1418C3A8EDB8")]
    class ATL_NO_VTABLE Network_Client : public Network_Client_, public CSmartPtrWrapper<Network::Client>
    {
    public:

        // \see Network_Client_::SetAttachment
        HRESULT SetAttachment(vbInt32 Attachment) override;

        // \see Network_Client_::GetAttachment
        HRESULT GetAttachment(vbInt32 * Result) override;

        // \see Network_Client_::SetProtocol
        HRESULT SetProtocol(Network_Protocol_ * Protocol) override;

        // \see Network_Client_::Poll
        HRESULT Poll();

        // \see Network_Client_::Flush
        HRESULT Flush();

        // \see Network_Client_::Close
        HRESULT Close(vbBool Forcibly) override;

        // \see Network_Client_::Write
        HRESULT Write(BinaryWriter_ * Message, Network_Channel Mode) override;

        // \see Network_Client_::GetStatistics
        HRESULT GetStatistics(Network_Statistics * Result) override;
    };
}