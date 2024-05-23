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

#include "Core/COM_Common.hpp"
#include <Network/Protocol.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace COM
{
    // -=(Undocumented)=-
    class VB6_Network_Protocol : public Network::Protocol
    {
    public:

        // -=(Undocumented)=-
        VB6_Network_Protocol();

        // -=(Undocumented)=-
        void Attach(UInt32 OnAttach, UInt32 OnDetach, UInt32 OnRead, UInt32 OnWrite);

        // \see Network::Protocol::OnConnect
        void OnConnect(ConstSPtr<class Network::Client> Session) override;

        // \see Network::Protocol::OnDisconnect
        void OnDisconnect(ConstSPtr<class Network::Client> Session) override;

        // \see Network::Protocol::OnRead
        void OnRead(ConstSPtr<class Network::Client> Session, CPtr<UInt08> Bytes) override;

        // \see Network::Protocol::OnWrite
        void OnWrite(ConstSPtr<class Network::Client> Session,  CPtr<UInt08> Bytes) override;

    private:

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        UInt32 mOnAttach;
        UInt32 mOnDetach;
        UInt32 mOnRead;
        UInt32 mOnWrite;
    };

    // -=(Undocumented)=-
    [object, uuid("39C1354D-C94C-11EE-ADEA-1418C3A8EDB8"), pointer_default(unique)]
    __interface Network_Protocol_
    {
        HRESULT Attach([in] vbInt32 OnAttach, [in] vbInt32 OnDetach, [in] vbInt32 OnRead, [in] vbInt32 OnWrite);
    };

    // -=(Undocumented)=-
    [coclass, uuid("39C1354D-C94C-11EE-ADEA-1418C3A8EDB7")]
    class ATL_NO_VTABLE Network_Protocol : public Network_Protocol_, public CSmartPtrWrapper<VB6_Network_Protocol>
    {
    public:

        // -=(Undocumented)=-
        HRESULT FinalConstruct();

        // \see Network_Protocol_::Attach
        HRESULT Attach(vbInt32 OnAttach, vbInt32 OnDetach, vbInt32 OnRead, vbInt32 OnWrite) override;
    };
}