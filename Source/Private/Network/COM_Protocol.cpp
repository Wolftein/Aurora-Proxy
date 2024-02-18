// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Copyright (C) 2021-2024 by Agustin Alvarez. All rights reserved.
//
// This work is licensed under the terms of the MIT license.
//
// For a copy, see <https://opensource.org/licenses/MIT>.
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [  HEADER  ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include "COM_Protocol.hpp"
#include "COM_Client.hpp"

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace COM
{
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    VB6_Network_Protocol::VB6_Network_Protocol()
        : mOnAttach { 0 },
          mOnDetach { 0 },
          mOnRead   { 0 },
          mOnWrite  { 0 },
          mOnError  { 0 }
    {
    }

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    void VB6_Network_Protocol::Attach(UInt32 OnAttach, UInt32 OnDetach, UInt32 OnRead, UInt32 OnWrite, UInt32 OnError)
    {
        mOnAttach = OnAttach;
        mOnDetach = OnDetach;
        mOnRead   = OnRead;
        mOnWrite  = OnWrite;
        mOnError  = OnError;
    }

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    void VB6_Network_Protocol::OnAttach(ConstSPtr<class Network::Client> Session)
    {
        using Declaration = void (STDAPICALLTYPE *)(CComObject<Network_Client> *);

        if (mOnAttach)
        {
            CComObject<Network_Client> * CComClient = CCreate<Network_Client>(Session);
            reinterpret_cast<Declaration>(mOnAttach)(CComClient);
        }
    }

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    void VB6_Network_Protocol::OnDetach(ConstSPtr<class Network::Client> Session)
    {
        using Declaration = void (STDAPICALLTYPE *)(CComObjectStackEx<Network_Client> *);

        if (mOnDetach)
        {
            CComObjectStackEx<Network_Client> CComClient = CCreateStack<Network_Client>(Session);
            reinterpret_cast<Declaration>(mOnDetach)(& CComClient);
        }
    }

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    void VB6_Network_Protocol::OnError(ConstSPtr<class Network::Client> Session, UInt Error, CStr Description)
    {
        using Declaration = void (STDAPICALLTYPE *)(CComObjectStackEx<Network_Client> *, vbInt32, vbStr16);

        if (mOnError)
        {
            CComObjectStackEx<Network_Client> CComClient = CCreateStack<Network_Client>(Session);
            reinterpret_cast<Declaration>(mOnError)(& CComClient, Error, VBString8ToString16(Description));
        }
    }

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    void VB6_Network_Protocol::OnRead(ConstSPtr<class Network::Client> Session,  CPtr<UInt08> Bytes)
    {
        using Declaration = void (STDAPICALLTYPE *)(CComObjectStackEx<Network_Client> *, CComObjectStackEx<BinaryReader> *);

        if (mOnRead)
        {
            CComObjectStackEx<Network_Client> CComClient = CCreateStack<Network_Client>(Session);
            CComObjectStackEx<BinaryReader>   CComReader = CCreateStack<BinaryReader>(Reader(Bytes));
            reinterpret_cast<Declaration>(mOnRead)(& CComClient, & CComReader);
        }
    }

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    void VB6_Network_Protocol::OnWrite(ConstSPtr<class Network::Client> Session, CPtr<UInt08> Bytes)
    {
        using Declaration = void (STDAPICALLTYPE *)(CComObjectStackEx<Network_Client> *, CComObjectStackEx<BinaryReader> *);

        if (mOnWrite)
        {
            CComObjectStackEx<Network_Client> CComClient = CCreateStack<Network_Client>(Session);
            CComObjectStackEx<BinaryReader>   CComReader = CCreateStack<BinaryReader>(Reader(Bytes));
            reinterpret_cast<Declaration>(mOnWrite)(& CComClient, & CComReader);
        }
    }

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    HRESULT Network_Protocol::FinalConstruct()
    {
        mWrapper = NewPtr<VB6_Network_Protocol>();
        return S_OK;
    }

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    HRESULT Network_Protocol::Attach(vbInt32 OnAttach, vbInt32 OnDetach, vbInt32 OnRead, vbInt32 OnWrite, vbInt32 OnError)
    {
        mWrapper->Attach(OnAttach, OnDetach, OnRead, OnWrite, OnError);
        return S_OK;
    }
}