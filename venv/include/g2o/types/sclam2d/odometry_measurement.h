// g2o - General Graph Optimization
// Copyright (C) 2011 R. Kuemmerle, G. Grisetti, W. Burgard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef G2O_ODOMETRY_MEASUREMENT_H
#define G2O_ODOMETRY_MEASUREMENT_H

#include <Eigen/Core>

#include "g2o/core/eigen_types.h"
#include "g2o_types_sclam2d_api.h"

namespace g2o {

/**
 * \brief velocity measurement of a differential robot
 */
class G2O_TYPES_SCLAM2D_API VelocityMeasurement {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
  VelocityMeasurement();
  VelocityMeasurement(double vl, double vr, double dt);

  [[nodiscard]] double vl() const { return measurement_(0); }
  void setVl(double v) { measurement_(0) = v; }

  [[nodiscard]] double vr() const { return measurement_(1); }
  void setVr(double v) { measurement_(1) = v; }

  [[nodiscard]] double dt() const { return dt_; }
  void setDt(double t) { dt_ = t; }

  [[nodiscard]] const Vector2& measurement() const { return measurement_; }

 protected:
  Vector2 measurement_;
  double dt_ = 0.;
};

/**
 * \brief A 2D odometry measurement expressed as a transformation
 */
class G2O_TYPES_SCLAM2D_API MotionMeasurement {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
  MotionMeasurement();
  MotionMeasurement(double x, double y, double theta, double dt);
  MotionMeasurement(Vector3 m, double dt);

  double x() const { return measurement_(0); }
  void setX(double v) { measurement_(0) = v; }

  double y() const { return measurement_(1); }
  void setY(double v) { measurement_(1) = v; }

  double theta() const { return measurement_(2); }
  void setTheta(double v) { measurement_(2) = v; }

  double dt() const { return dt_; }
  void setDt(double t) { dt_ = t; }

  const Vector3& measurement() const { return measurement_; }

 protected:
  Vector3 measurement_;
  double dt_ = 0.;
};

/**
 * \brief convert between the different types of odometry measurements
 */
class G2O_TYPES_SCLAM2D_API OdomConvert {
 public:
  static VelocityMeasurement convertToVelocity(const MotionMeasurement& m);
  static MotionMeasurement convertToMotion(const VelocityMeasurement& vi,
                                           double l = 1.0);
};

}  // namespace g2o

#endif
