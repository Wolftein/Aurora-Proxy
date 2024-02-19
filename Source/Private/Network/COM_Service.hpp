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

#include "COM_Client.hpp"
#include "COM_Server.hpp"
#include <Network/Service.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace COM
{
    // -=(Undocumented)=-
    [object, uuid("12E95A24-C94A-11EE-ADEA-1418C3A8EDB8"), pointer_default(unique)]
    __interface Network_Service_
    {
        HRESULT Listen([in] vbStr8 Address, [in] vbInt32 Port, [out, retval] Network_Server_ ** Result);

        HRESULT Connect([in] vbStr8 Address, [in] vbInt32 Port, [out, retval] Network_Client_ ** Result);
    };

    // -=(Undocumented)=-
    [coclass, uuid("1998E627-C94A-11EE-ADEA-1418C3A8EDB8")]
    class ATL_NO_VTABLE Network_Service : public Network_Service_, public CSmartPtrWrapper<Network::Service>
    {
    public:

        // \see Network_Service_::Listen
        HRESULT Listen(vbStr8 Address, vbInt32 Port, Network_Server_ ** Result) override;

        // \see Network_Service_::Connect
        HRESULT Connect(vbStr8 Address, vbInt32 Port, Network_Client_ ** Result) override;
    };
}