#include "legendrepoly.h"
#include <cmath>

double fac(int x)
{
  if (x==0) return 1;
  if (x==1) return 1;

  return fac(x-1)*x;
}

//###################################################################
/**Implementation of the tesseral spherical harmonics.
 *
 * This code has a whitepaper associated with it
 * <a href="SphericalHarmonics.pdf" target="_blank"><b>Spherical Harmonics</b></a>
 * */
double chi_math::Ylm(int ell, int m, double varphi, double theta)
{
  double el = 1.0*ell;
  double em = 1.0*m;

  if (em<0)
  {
    return sqrt( ( 2.0 ) * fac(el-std::fabs(em))/fac(el+std::fabs(em)) )*
           AssocLegendre(el,std::fabs(em),cos(theta))*
           sin(std::fabs(em)*varphi);
  }
  else if(em==0)
  {
    return AssocLegendre(el,em,cos(theta));
  }
  else
  {
    return  sqrt( ( 2.0 ) * fac(el-em)/fac(el+em) )*
            AssocLegendre(el,em,cos(theta))*
            cos(em*varphi);
  }

  return 0.0;
}