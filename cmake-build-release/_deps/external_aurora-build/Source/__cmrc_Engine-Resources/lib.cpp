        #include <cmrc/cmrc.hpp>
#include <map>
#include <utility>

namespace cmrc {
namespace Resources {

namespace res_chars {
// These are the files which are available in this resource library
// Pointers to C:/Users/Agustin/Workspace/Aurora-Proxy/cmake-build-release/_deps/external_aurora-src/Source/Resources/Pipeline/Font.effect
extern const char* const f_d8af_Pipeline_Font_effect_begin;
extern const char* const f_d8af_Pipeline_Font_effect_end;
// Pointers to C:/Users/Agustin/Workspace/Aurora-Proxy/cmake-build-release/_deps/external_aurora-src/Source/Resources/Pipeline/Font.shader
extern const char* const f_d195_Pipeline_Font_shader_begin;
extern const char* const f_d195_Pipeline_Font_shader_end;
// Pointers to C:/Users/Agustin/Workspace/Aurora-Proxy/cmake-build-release/_deps/external_aurora-src/Source/Resources/Pipeline/Geometry.effect
extern const char* const f_83b6_Pipeline_Geometry_effect_begin;
extern const char* const f_83b6_Pipeline_Geometry_effect_end;
// Pointers to C:/Users/Agustin/Workspace/Aurora-Proxy/cmake-build-release/_deps/external_aurora-src/Source/Resources/Pipeline/Geometry.shader
extern const char* const f_2620_Pipeline_Geometry_shader_begin;
extern const char* const f_2620_Pipeline_Geometry_shader_end;
// Pointers to C:/Users/Agustin/Workspace/Aurora-Proxy/cmake-build-release/_deps/external_aurora-src/Source/Resources/Pipeline/UI.effect
extern const char* const f_4fb2_Pipeline_UI_effect_begin;
extern const char* const f_4fb2_Pipeline_UI_effect_end;
// Pointers to C:/Users/Agustin/Workspace/Aurora-Proxy/cmake-build-release/_deps/external_aurora-src/Source/Resources/Pipeline/UI.shader
extern const char* const f_5a47_Pipeline_UI_shader_begin;
extern const char* const f_5a47_Pipeline_UI_shader_end;
}

namespace {

const cmrc::detail::index_type&
get_root_index() {
    static cmrc::detail::directory root_directory_;
    static cmrc::detail::file_or_directory root_directory_fod{root_directory_};
    static cmrc::detail::index_type root_index;
    root_index.emplace("", &root_directory_fod);
    struct dir_inl {
        class cmrc::detail::directory& directory;
    };
    dir_inl root_directory_dir{root_directory_};
    (void)root_directory_dir;
    static auto f_aeae_Pipeline_dir = root_directory_dir.directory.add_subdir("Pipeline");
    root_index.emplace("Pipeline", &f_aeae_Pipeline_dir.index_entry);
    root_index.emplace(
        "Pipeline/Font.effect",
        f_aeae_Pipeline_dir.directory.add_file(
            "Font.effect",
            res_chars::f_d8af_Pipeline_Font_effect_begin,
            res_chars::f_d8af_Pipeline_Font_effect_end
        )
    );
    root_index.emplace(
        "Pipeline/Font.shader",
        f_aeae_Pipeline_dir.directory.add_file(
            "Font.shader",
            res_chars::f_d195_Pipeline_Font_shader_begin,
            res_chars::f_d195_Pipeline_Font_shader_end
        )
    );
    root_index.emplace(
        "Pipeline/Geometry.effect",
        f_aeae_Pipeline_dir.directory.add_file(
            "Geometry.effect",
            res_chars::f_83b6_Pipeline_Geometry_effect_begin,
            res_chars::f_83b6_Pipeline_Geometry_effect_end
        )
    );
    root_index.emplace(
        "Pipeline/Geometry.shader",
        f_aeae_Pipeline_dir.directory.add_file(
            "Geometry.shader",
            res_chars::f_2620_Pipeline_Geometry_shader_begin,
            res_chars::f_2620_Pipeline_Geometry_shader_end
        )
    );
    root_index.emplace(
        "Pipeline/UI.effect",
        f_aeae_Pipeline_dir.directory.add_file(
            "UI.effect",
            res_chars::f_4fb2_Pipeline_UI_effect_begin,
            res_chars::f_4fb2_Pipeline_UI_effect_end
        )
    );
    root_index.emplace(
        "Pipeline/UI.shader",
        f_aeae_Pipeline_dir.directory.add_file(
            "UI.shader",
            res_chars::f_5a47_Pipeline_UI_shader_begin,
            res_chars::f_5a47_Pipeline_UI_shader_end
        )
    );
    return root_index;
}

}

cmrc::embedded_filesystem get_filesystem() {
    static auto& index = get_root_index();
    return cmrc::embedded_filesystem{index};
}

} // Resources
} // cmrc
    