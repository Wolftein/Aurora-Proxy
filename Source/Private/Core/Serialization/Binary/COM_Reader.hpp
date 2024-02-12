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
#include <Core/Serialization/Binary/Reader.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace COM
{
    // -=(Undocumented)=-
    [object, uuid("763CBB84-C943-11EE-ADEA-1418C3A8EDB8"), pointer_default(unique)]
    __interface BinaryReader_
    {
        HRESULT SetData([in, satype(vbInt8)] SAFEARRAY ** Result);

        HRESULT GetData([in, satype(vbInt8)] SAFEARRAY ** Result);

        HRESULT GetCapacity([out, retval] vbInt32 * Result);

        HRESULT GetOffset([out, retval] vbInt32 * Result);

        HRESULT GetAvailable([out, retval] vbInt32 * Result);

        HRESULT Skip([in] vbInt32 Length);

        [local] HRESULT Read([in] vbAny Address, [in] vbInt32 Length);

        HRESULT ReadBool([out, retval] vbBool * Result);

        HRESULT ReadInt([out, retval] vbInt32 * Result);

        HRESULT ReadInt8([out, retval] vbInt8 * Result);

        HRESULT ReadInt16([out, retval] vbInt16 * Result);

        HRESULT ReadInt32([out, retval] vbInt32 * Result);

        HRESULT ReadInt64([out, retval] vbInt64 * Result);

        HRESULT ReadReal32([out, retval] vbReal32 * Result);

        HRESULT ReadReal64([out, retval] vbReal64 * Result);

        HRESULT ReadString8([out, retval] vbStr16 * Result);

        HRESULT ReadString16([out, retval] vbStr16 * Result);

        HRESULT ReadSafeArrayInt8([in, satype(vbInt8)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayInt16([in, satype(vbInt16)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayInt32([in, satype(vbInt32)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayInt64([in, satype(vbInt64)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayReal32([in, satype(vbReal32)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayReal64([in, satype(vbReal64)] SAFEARRAY ** Value);
    };

    // -=(Undocumented)=-
    [coclass, uuid("767D45C2-C943-11EE-ADEA-1418C3A8EDB8")]
    class ATL_NO_VTABLE BinaryReader : public BinaryReader_, public CObjectWrapper<Core::Reader>
    {
    public:

        // \see Reader_::SetData
        HRESULT SetData(SAFEARRAY ** Result);

        // \see Reader_::GetData
        HRESULT GetData(SAFEARRAY ** Result);

        // \see Reader_::GetCapacity
        HRESULT GetCapacity(vbInt32 * Result);

        // \see Reader_::GetOffset
        HRESULT GetOffset(vbInt32 * Result);

        // \see Reader_::GetAvailable
        HRESULT GetAvailable(vbInt32 * Result);

        // \see Reader_::Skip
        HRESULT Skip(vbInt32 Length);

        // \see Reader_::Read
        HRESULT Read(vbAny Address, vbInt32 Length);

        // \see Reader_::ReadBool
        HRESULT ReadBool(vbBool * Result);

        // \see Reader_::ReadInt
        HRESULT ReadInt(vbInt32 * Result);

        // \see Reader_::ReadInt8
        HRESULT ReadInt8(vbInt8 * Result);

        // \see Reader_::ReadInt16
        HRESULT ReadInt16(vbInt16 * Result);

        // \see Reader_::ReadInt32
        HRESULT ReadInt32(vbInt32 * Result);

        // \see Reader_::ReadInt64
        HRESULT ReadInt64(vbInt64 * Result);

        // \see Reader_::ReadReal32
        HRESULT ReadReal32(vbReal32 * Result);

        // \see Reader_::ReadReal64
        HRESULT ReadReal64(vbReal64 * Result);

        // \see Reader_::ReadString8
        HRESULT ReadString8(vbStr16 * Result);

        // \see Reader_::ReadString16
        HRESULT ReadString16(vbStr16 * Result);

        // \see Reader_::ReadSafeArrayInt8
        HRESULT ReadSafeArrayInt8(SAFEARRAY ** Value);

        // \see Reader_::ReadSafeArrayInt16
        HRESULT ReadSafeArrayInt16(SAFEARRAY ** Value);

        // \see Reader_::ReadSafeArrayInt32
        HRESULT ReadSafeArrayInt32(SAFEARRAY ** Value);

        // \see Reader_::ReadSafeArrayInt64
        HRESULT ReadSafeArrayInt64(SAFEARRAY ** Value);

        // \see Reader_::ReadSafeArrayReal32
        HRESULT ReadSafeArrayReal32(SAFEARRAY ** Value);

        // \see Reader_::ReadSafeArrayReal64
        HRESULT ReadSafeArrayReal64(SAFEARRAY ** Value);

    private:

        // -=(Undocumented)=-
        HRESULT ReadSafeArray(SAFEARRAY ** Value, VARTYPE Type, UInt32 Element);
    };
}