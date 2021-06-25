// https://github.com/mrdoob/three.js/blob/r129/src/objects/Points.js

#ifndef THREEPP_POINTS_HPP
#define THREEPP_POINTS_HPP

#include "threepp/core/Object3D.hpp"
#include "threepp/materials/PointsMaterial.hpp"

namespace threepp {

    class Points : public Object3D {

    public:
        static std::shared_ptr<Points> create(
                const std::shared_ptr<BufferGeometry> &geometry = BufferGeometry::create(),
                const std::shared_ptr<Material> &material = PointsMaterial::create()) {

            return std::shared_ptr<Points>(new Mesh(std::move(geometry), std::move(material)));
        }

        ~Points() = default;

    protected:
        Points(std::shared_ptr<BufferGeometry> geometry, std::shared_ptr<Material> material)
            : geometry_(std::move(geometry)), material_(std::move(material)) {
        }

    private:
        std::shared_ptr<BufferGeometry> geometry_;
        std::shared_ptr<Material> material_;
    };

}// namespace threepp

#endif//THREEPP_POINTS_HPP