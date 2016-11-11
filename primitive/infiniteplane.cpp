#include <cmath>
#include <algorithm>
#include "primitive/infiniteplane.h"


// Constructor /////////////////////////////////////////////////////////////////

InfinitePlane::InfinitePlane(Shader * shader)
  : Primitive(shader), normal_(0,1,0) {}

InfinitePlane::InfinitePlane(Vector3d const& origin, Vector3d const& normal, Shader * shader)
  : Primitive(shader), origin_(origin), normal_(normal) {}


// Primitive functions /////////////////////////////////////////////////////////

bool InfinitePlane::intersect(Ray * ray) const {
  // Calculation of intersection using hesse normal form
  Vector3d difference = origin_ - ray->origin;

  float equation_denominator = dotProduct(ray->direction, normal_);

  if (equation_denominator > -std::numeric_limits<float_t>::epsilon() && equation_denominator < std::numeric_limits<float_t>::epsilon())
    return false;

  float distance_normal = dotProduct(difference, normal_) / equation_denominator;

  if (distance_normal < std::numeric_limits<float_t>::epsilon() || distance_normal > ray->length)
    return false;

  ray->length = distance_normal;
  ray->primitive = this;
  return true;
}

Vector3d InfinitePlane::normalFromRay(Ray const& ray) const {
  return normal_;
}


// Bounding box ////////////////////////////////////////////////////////////////

float InfinitePlane::minimumBounds(int dimension) const {
 /*
  * IMPLEMENT ME!
  *
  * These values are used for determining the bounding box.
  * This should return the minimum value along the given dimension.
  *
  */
  return -INFINITY;
}

float InfinitePlane::maximumBounds(int dimension) const {
 /*
  * IMPLEMENT ME!
  *
  * These values are used for determining the bounding box.
  * This should return the maximum value along the given dimension.
  *
  */
  return +INFINITY;
}
