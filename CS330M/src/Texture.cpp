//
// Created by Dsk3 on 9/23/2023.
//

#include <Texture.h>
#include <stb_image.h>
#include <iostream>

Texture::Texture(const std::filesystem::path &path, const SamplerSettings& samplerSettings) :  _samplerSettings { samplerSettings } {
    // Load the image data
    // Flip the image vertically on load
    stbi_set_flip_vertically_on_load(true);
    auto texturePath = (TexturePath / path).string();

    int width, height, numChannels;
    unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &numChannels, STBI_rgb_alpha);

    // Generate a texture handle
    glGenTextures(1, &_textureHandle);
    glBindTexture(GL_TEXTURE_2D, _textureHandle);

    if (data) {
        // Load the texture into the GPU
        glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, width, height);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "Failed to load texture at path: " << texturePath << std::endl;
    }

    // Free the image data
    stbi_image_free(data);
}

void Texture::Bind() const {
    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, _textureHandle);
    bindSamplerSettings();
}


void Texture::bindSamplerSettings() const {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, samplerTileModeToGLenum(_samplerSettings.S));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, samplerTileModeToGLenum(_samplerSettings.T));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, samplerFilterModeToGLenum(_samplerSettings.MinFilter));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, samplerFilterModeToGLenum(_samplerSettings.MagFilter));
}

int Texture::samplerTileModeToGLenum(Texture::SamplerTileMode mode) const {
    switch (mode) {
        case SamplerTileMode::Repeat:
            return GL_REPEAT;
            break;
        case SamplerTileMode::MirroredRepeat:
            return GL_MIRRORED_REPEAT;
            break;
        case SamplerTileMode::ClampToEdge:
            return GL_CLAMP_TO_EDGE;
            break;

    }
}

int Texture::samplerFilterModeToGLenum(Texture::SamplerFilterMode mode) const {
    switch (mode) {
        case SamplerFilterMode::Nearest:
            return GL_NEAREST;
            break;
        case SamplerFilterMode::Linear:
            return GL_LINEAR;
            break;
        case SamplerFilterMode::NearestMipmapNearest:
            return GL_NEAREST_MIPMAP_NEAREST;
            break;
        case SamplerFilterMode::LinearMipmapNearest:
            return GL_LINEAR_MIPMAP_NEAREST;
            break;
        case SamplerFilterMode::NearestMipmapLinear:
            return GL_NEAREST_MIPMAP_LINEAR;
            break;
        case SamplerFilterMode::LinearMipmapLinear:
            return GL_LINEAR_MIPMAP_LINEAR;
            break;
    }
}