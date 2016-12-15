#include "primitive/texturedtriangle.h"


// Constructor /////////////////////////////////////////////////////////////////

TexturedTriangle::TexturedTriangle(Shader * shader)
  : SmoothTriangle(shader) {}

TexturedTriangle::TexturedTriangle(Vector3d const& a, Vector3d const& b, Vector3d const& c,
                               Vector3d const& na, Vector3d const& nb, Vector3d const& nc,
                               Vector2d const& ta, Vector2d const& tb, Vector2d const& tc,
                               Shader * shader)
  : SmoothTriangle(a,b,c,na,nb,nc,shader), textureCoordinates_{ta, tb, tc} {}


// Primitive functions /////////////////////////////////////////////////////////

Vector2d TexturedTriangle::uvFromRay(Ray const& ray) const {
  // Implement me!
  Vector2d normal(0,0);
  return normal;
}
