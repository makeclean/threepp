// https://github.com/mrdoob/three.js/blob/r129/src/renderers/webgl/WebGLPrograms.js

#ifndef THREEPP_GLPROGRAMS_HPP
#define THREEPP_GLPROGRAMS_HPP

#include "GLLights.hpp"
#include "GLCapabilities.hpp"

#include "threepp/core/Object3D.hpp"
#include "threepp/materials/Material.hpp"
#include "threepp/scenes/Scene.hpp"
#include "threepp/textures/Texture.hpp"

#include <glad/glad.h>

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <optional>

namespace threepp::gl {

    struct GLPrograms {

        struct Parameters {

            std::string shaderId;
            std::string shaderName;

            std::string vertexShader;
            std::string fragmentShader;

            bool isRawShaderMaterial;

            bool supportsVertexTextures;
            int outputEncoding;

            int numDirLights;
            int numPointLights;
            int numSpotLights;

            int numDirLightShadows;
            int numPointLightShadows;
            int numSpotLightShadows;
            int numRectAreaLights;
            int numHemiLights;

            int numClippingPlanes;
            int numClipIntersection;

            bool dithering;

            bool shadowMapEnabled;
            int shadowMapType;

            int toneMapping;
            bool physicallyCorrectLights;

            bool premultipliedAlpha;

            bool alphaTest;
            bool doubleSided;
            bool flipSided;

            bool depthPacking;

            std::string index0AttributeName;

            std::string customProgramCacheKey;

            Parameters(
                    const GLPrograms &scope,
                    Material *material,
                    GLLights::LightState &lights,
                    int numShadows,
                    Scene* scene,
                    Object3D *object);
        };


        bool logarithmicDepthBuffer;
        bool floatVertexTextures;
        GLint maxVertexUniforms;
        bool vertexTextures;

        GLPrograms();

        int getTextureEncodingFromMap(std::optional<Texture> &map) const;

        Parameters getParameters(Material* material, GLLights::LightState &lights, int numShadows, Scene* scene, Object3D* object);

    };

}// namespace threepp::gl

#endif//THREEPP_GLPROGRAMS_HPP
