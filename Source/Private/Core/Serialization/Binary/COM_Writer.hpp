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
#include <Core/Serialization/Binary/Writer.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace COM
{
    // -=(Undocumented)=-
    [object, uuid("891140A0-C943-11EE-ADEA-1418C3A8EDB8"), pointer_default(unique)]
    __interface BinaryWriter_
    {
        HRESULT Clear();

        HRESULT GetData([in, satype(vbInt8)] SAFEARRAY ** Result);

        HRESULT GetCapacity([out, retval] vbInt32 * Result);

        HRESULT GetOffset([out, retval] vbInt32 * Result);

        HRESULT GetAvailable([out, retval] vbInt32 * Result);

        [local] HRESULT Write([in] vbAny Address, [in] vbInt32 Length);

        HRESULT WriteBool([in] vbBool Value);

        HRESULT WriteInt([in] vbInt32 Value);

        HRESULT WriteInt8([in] vbInt8 Value);

        HRESULT WriteInt16([in] vbInt16 Value);

        HRESULT WriteInt32([in] vbInt32 Value);

        HRESULT WriteInt64([in] vbInt64 Value);

        HRESULT WriteReal32([in] vbReal32 Value);

        HRESULT WriteReal64([in] vbReal64 Value);

        HRESULT WriteString8([in] vbStr16 Value);

        HRESULT WriteString16([in] vbStr16 Value);

        HRESULT WriteSafeArrayInt8([in, satype(vbInt8)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayInt16([in, satype(vbInt16)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayInt32([in, satype(vbInt32)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayInt64([in, satype(vbInt64)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayReal32([in, satype(vbReal32)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayReal64([in, satype(vbReal64)] SAFEARRAY ** Value);
    };

    // -=(Undocumented)=-
    [coclass, uuid("8AAA199E-C943-11EE-ADEA-1418C3A8EDB8")]
    class ATL_NO_VTABLE BinaryWriter : public BinaryWriter_, public CObjectWrapper<Core::Writer>
    {
    public:

        // \see Writer_::Clear
        HRESULT Clear();

        // \see Writer_::GetData
        HRESULT GetData(SAFEARRAY ** Result);

        // \see Writer_::GetCapacity
        HRESULT GetCapacity(vbInt32 * Result);

        // \see Writer_::GetOffset
        HRESULT GetOffset(vbInt32 * Result);

        // \see Writer_::GetAvailable
        HRESULT GetAvailable(vbInt32 * Result);

        // \see Writer_::Write
        HRESULT Write(vbAny Address, vbInt32 Length);

        // \see Writer_::WriteBool
        HRESULT WriteBool(vbBool Value);

        // \see Writer_::WriteInt
        HRESULT WriteInt(vbInt32 Value);

        // \see Writer_::WriteInt8
        HRESULT WriteInt8(vbInt8 Value);

        // \see Writer_::WriteInt16
        HRESULT WriteInt16(vbInt16 Value);

        // \see Writer_::WriteInt32
        HRESULT WriteInt32(vbInt32 Value);

        // \see Writer_::WriteInt64
        HRESULT WriteInt64(vbInt64 Value);

        // \see Writer_::WriteReal32
        HRESULT WriteReal32(vbReal32 Value);

        // \see Writer_::WriteReal64
        HRESULT WriteReal64(vbReal64 Value);

        // \see Writer_::WriteString8
        HRESULT WriteString8(vbStr16 Value);

        // \see Writer_::WriteString16
        HRESULT WriteString16(vbStr16 Value);

        // \see Writer_::WriteSafeArrayInt8
        HRESULT WriteSafeArrayInt8(SAFEARRAY ** Value);

        // \see Writer_::WriteSafeArrayInt16
        HRESULT WriteSafeArrayInt16(SAFEARRAY ** Value);

        // \see Writer_::WriteSafeArrayInt32
        HRESULT WriteSafeArrayInt32(SAFEARRAY ** Value);

        // \see Writer_::WriteSafeArrayInt64
        HRESULT WriteSafeArrayInt64(SAFEARRAY ** Value);

        // \see Writer_::WriteSafeArrayReal32
        HRESULT WriteSafeArrayReal32(SAFEARRAY ** Value);

        // \see Writer_::WriteSafeArrayReal64
        HRESULT WriteSafeArrayReal64(SAFEARRAY ** Value);

    private:

        // -=(Undocumented)=-
        HRESULT WriteSafeArray(SAFEARRAY * Value);
    };
}