//
// Created by Dsk3 on 9/23/2023.
//

#include <Texture.h>
#include <stb_image.h>
#include <iostream>

Texture::Texture(const std::filesystem::path &path) {
    // Load a texture
    stbi_set_flip_vertically_on_load(true);

    auto texturePath = path.string();

    int width, height, numChannels;
    unsigned char *data = stbi_load(texturePath.c_str(), &width, &height, &numChannels, STBI_rgb_alpha);

    glGenTextures(1, &_textureHandle);
    glBindTexture(GL_TEXTURE_2D, _textureHandle);
    if (data){
        glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, width, height);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void Texture::Bind() {
    glBindTexture(GL_TEXTURE_2D, _textureHandle);
}
