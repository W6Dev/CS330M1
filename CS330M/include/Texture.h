//
// Created by Dsk3 on 9/23/2023.
//
#pragma once
#include <filesystem>
#include <glad/glad.h>
using Path = std::filesystem::path;


class Texture {
public:
    enum class SamplerTileMode {
        Repeat,
        MirroredRepeat,
        ClampToEdge,
    };
    enum class SamplerFilterMode {
        Nearest,
        Linear,
        NearestMipmapNearest,
        LinearMipmapNearest,
        NearestMipmapLinear,
        LinearMipmapLinear
    };

    struct SamplerSettings {
        SamplerTileMode S {SamplerTileMode::Repeat };
        SamplerTileMode T {SamplerTileMode::Repeat };

        SamplerFilterMode MinFilter { SamplerFilterMode::Linear };
        SamplerFilterMode MagFilter { SamplerFilterMode::Linear };

        static SamplerSettings Default() {
            return {};
        }
    };

    static inline Path TexturePath = std::filesystem::current_path() / "assets" / "textures";
    explicit Texture(const std::filesystem::path& path, const SamplerSettings& samplerSettings = SamplerSettings::Default());
    void Bind() const;
    const SamplerSettings& GetSamplerSettings() { return _samplerSettings; }
    void SetSamplerSettings(const SamplerSettings& newSettings) { _samplerSettings = newSettings; }

private:
    void bindSamplerSettings() const;
    int samplerTileModeToGLenum(SamplerTileMode mode) const;
    int samplerFilterModeToGLenum(SamplerFilterMode mode) const;
private:
    GLuint _textureHandle{};
    SamplerSettings _samplerSettings {};
};
