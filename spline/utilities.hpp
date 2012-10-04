// This file is part of the imaging2 class library.
//
// University of Innsbruck, Infmath Imaging, 2009.
// http://infmath.uibk.ac.at
//
// All rights reserved.


#ifndef SPLINE_UTILITIES_H
#define SPLINE_UTILITIES_H
 
#include <spline/Bspline.hpp>
#include <spline/PeriodicBspline.hpp>

namespace imaging
{ 
  /** \ingroup spline
      <tt>\#include <spline/utilities.hpp></tt>
     
      Sets the <em>i</em>-th spline coefficient of \em spline to 1 and all the others to 0.
  */
  void basis_spline(size_t i, Bspline<float_t> & spline);
  
  /** \ingroup spline
      <tt>\#include <spline/utilities.hpp></tt>
     
      Sets the <em>i</em>-th spline coefficient of \em spline to 1 and all the others to 0. */
  void basis_spline(size_t i, PeriodicBspline<float_t> & spline);
  
  /** \ingroup spline
      <tt>\#include <spline/utilities.hpp></tt>
     
      Computes the matrix which is the result of the spline interpolation problem. Assume a B-spline function
      \f[
        s(\tau) = \sum_{i = 0}^n a_i b_i(\tau)
      \f]
      and consider the interpolation problem
      \f[
        s(\tau_k) = y_k\,,\quad 0 \leq k \leq N\,.
      \f]
      Then the least squares solution of this problem is defined by the system of linear equations
      \f[
        \sum_{i=0}^n a_i \underbrace{\sum_{k=0}^N b_i(\tau_k)b_j(\tau_k)}_{A_{ij}} =
        \sum_{j=0}^N \underbrace{b_j(\tau_k)}_{B_{jk}} y_k\,,\quad 0 \leq j \leq n\,.
      \f]
      If \f$s\f$ is given by \em spline and \f$(\tau_k)_{0\leq k \leq N}\f$ by \em values, then this function writes \f$A\f$ to \em matrix.
  */
  void interpolation_matrix(const Bspline<float_t> & spline, const ublas::vector<float_t> & values, ublas::compressed_matrix< float_t > & matrix);
  
  /** \ingroup spline
      <tt>\#include <spline/utilities.hpp></tt>
     
      Computes the matrix which is the result of the spline interpolation problem. Assume a B-spline function
      \f[
        s(\tau) = \sum_{i = 0}^n a_i b_i(\tau)
      \f]
      and consider the interpolation problem
      \f[
        s(\tau_k) = y_k\,,\quad 0 \leq k \leq N\,.
      \f]
      Then the least squares solution of this problem is defined by the system of linear equations
      \f[
        \sum_{i=0}^n a_i \underbrace{\sum_{k=0}^N b_i(\tau_k)b_j(\tau_k)}_{A_{ij}} =
        \sum_{j=0}^N \underbrace{b_j(\tau_k)}_{B_{jk}} y_k\,,\quad 0 \leq j \leq n\,.
      \f]
      If \f$s\f$ is given by \em spline and \f$(\tau_k)_{0\leq k \leq N}\f$ by \em values, then this function writes \f$A\f$ to \em matrix.
  */
  void interpolation_matrix(const PeriodicBspline<float_t> & spline, const ublas::vector<float_t> & values, ublas::compressed_matrix< float_t > & matrix);
  
  /** \ingroup spline
      <tt>\#include <spline/utilities.hpp></tt>
     
      Computes the matrix which is the result of the spline interpolation problem. Assume a B-spline function
      \f[
        s(\tau) = \sum_{i = 0}^n a_i b_i(\tau)
      \f]
      and consider the interpolation problem
      \f[
        s(\tau_k) = y_k\,,\quad 0 \leq k \leq N\,.
      \f]
      Then the least squares solution of this problem is defined by the system of linear equations
      \f[
        \sum_{i=0}^n a_i \underbrace{\sum_{k=0}^N b_i(\tau_k)b_j(\tau_k)}_{A_{ij}} =
        \sum_{j=0}^N \underbrace{b_j(\tau_k)}_{B_{jk}} y_k\,,\quad 0 \leq j \leq n\,.
      \f]
      If \f$s\f$ is given by \em spline and \f$(\tau_k)_{0\leq k \leq N}\f$ by \em values, then this function writes \f$B\f$ to \em matrix.
  */
  void basis_spline_matrix(const PeriodicBspline<float_t> & spline, const ublas::vector<float_t> & values, ublas::compressed_matrix< float_t > & matrix);
  
  /** \ingroup spline
      <tt>\#include <spline/utilities.hpp></tt>
     
      Computes the matrix which is the result of the spline interpolation problem. Assume a B-spline function
      \f[
        s(\tau) = \sum_{i = 0}^n a_i b_i(\tau)
      \f]
      and consider the interpolation problem
      \f[
        s(\tau_k) = y_k\,,\quad 0 \leq k \leq N\,.
      \f]
      Then the least squares solution of this problem is defined by the system of linear equations
      \f[
        \sum_{i=0}^n a_i \underbrace{\sum_{k=0}^N b_i(\tau_k)b_j(\tau_k)}_{A_{ij}} =
        \sum_{j=0}^N \underbrace{b_j(\tau_k)}_{B_{jk}} y_k\,,\quad 0 \leq j \leq n\,.
      \f]
      If \f$s\f$ is given by \em spline and \f$(\tau_k)_{0\leq k \leq N}\f$ by \em values, then this function writes \f$B\f$ to \em matrix.
  */
  void basis_spline_matrix(const Bspline<float_t> & spline, const ublas::vector<float_t> & values, ublas::compressed_matrix< float_t > & matrix);
  
  /** \cond */
  namespace spline_utilities_impl
  { 
    template <class spline_t>
    void basis_spline(size_t i, spline_t & spline);
    
    template <class spline_t>
    void interpolation_matrix(const spline_t & spline, const ublas::vector<float_t> & values, ublas::compressed_matrix< float_t > & matrix);
    
    template <class spline_t>
    void basis_spline_matrix(const spline_t & spline, const ublas::vector<float_t> & values, ublas::compressed_matrix< float_t > & matrix);
  }
  /** \endcond */
}
 
 
#endif
