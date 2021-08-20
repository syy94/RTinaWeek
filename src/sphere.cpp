#include "sphere.hpp"

sphere::sphere(){};
sphere::sphere(point3 cen, double r): center(cen), radius(r) {};
sphere::sphere(point3 cen, double r, shared_ptr<material> m)
            : center(cen), radius(r), mat_ptr(m) {};


bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    // quadtractic equation to find if t exists. if t exists, it means it hit the sphere.

    //t^2b⋅b + 2tb⋅(A−C) + (A−C)⋅(A−C) − r2 = 0

    vec3 oc = r.origin() - center; //(A-C)
    auto a = r.direction().length_squared(); // b⋅b
    auto half_b = dot(oc, r.direction()); // b⋅(A−C)
    auto c = oc.length_squared() - radius*radius; //(A−C)⋅(A−C) − r2

    auto discriminant = half_b*half_b - a*c; //formula under square root after removing factor of 2 (optimization)

    if (discriminant < 0) return false; // no real roots since negative

    auto sqrtd = sqrt(discriminant);

    // Find the nearest root from the origin that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    //record where the ray hits
    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}
