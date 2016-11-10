#include <algorithm>
#include "primitive/triangle.h"


// Constructor /////////////////////////////////////////////////////////////////

Triangle::Triangle(Shader * shader)
  : Primitive(shader) {}

Triangle::Triangle(Vector3d const& a, Vector3d const& b, Vector3d const& c, Shader * shader)
  : Primitive(shader), vertex_{a,b,c} {}


// Primitive functions /////////////////////////////////////////////////////////

bool Triangle::intersect(Ray * ray) const {
  // Span plane defined by vertices of triangle
  // Using a as base vector and edges between a,b and a,c

  Vector3d a = vertex_[0], b = vertex_[1], c = vertex_[2];

  Vector3d edge1 = b - a;
  Vector3d edge2 = c - a;

  Vector3d pvec = crossProduct(ray->direction , edge2);

  float det = dotProduct(edge1, pvec);
  float inv_det = 1.0f / det;

  Vector3d tvec = ray->origin - a;
  float lambda = dotProduct(tvec, pvec);
  lambda *= inv_det;

  if (lambda < 0.0f || lambda > 1.0f) {
    return false;
  }

  Vector3d qvec = crossProduct(tvec , edge1);
  float mue = dotProduct(ray->direction, qvec);
  mue *= inv_det;

  if (mue < 0.0f || mue + lambda > 1.0f) {
    return false;
  }

  float f = dotProduct(edge2, qvec);
  f *= inv_det;
  if (ray->length <= f) {
    return false;
  }

  ray->length = f;
  ray->primitive = this;

  return true;
}

Vector3d Triangle::normalFromRay(Ray const& ray) const {
  Vector3d normal = crossProduct(Vector3d(vertex_[1] - vertex_[0]),Vector3d(vertex_[2] - vertex_[0]));
  normalize(&normal);

  return normal;
}


// Bounding box ////////////////////////////////////////////////////////////////

float Triangle::minimumBounds(int dimension) const {
 /*
  * IMPLEMENT ME!
  *
  * These values are used for determining the bounding box.
  * This should return the minimum value along the given dimension.
  *
  */
  return -INFINITY;
}

float Triangle::maximumBounds(int dimension) const {
 /*
  * IMPLEMENT ME!
  *
  * These values are used for determining the bounding box.
  * This should return the maximum value along the given dimension.
  *
  */
  return +INFINITY;
}
