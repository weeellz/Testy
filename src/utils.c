/*!
 * @author fexolm 
 * @date 09.04.18.
 */

#include <math.h>

const double testy_EPSILON = (1.0E-8);
const double testy_SMALL_EPSILON = (1.0E-150);

int testy_compareDouble(double lhs, double rhs) {
  double diff = lhs - rhs;
  double absDiff = fabs(diff);
  if (absDiff < testy_SMALL_EPSILON) {
    return 0;
  }
  double maxAbs = fmax(fabs(lhs) - fabs(rhs));
  if (absDiff/maxAbs < testy_EPSILON) {
    return 0;
  }
  return diff > 0 ? 1 : -1;
}