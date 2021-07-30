#include <iostream>
#include <vector>
#include "Eigen/Dense"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::cout;
using std::endl;

MatrixXd CalculateJacobian(const VectorXd& x_state);

int main() {
  /**
   * Compute the Jacobian Matrix
   */

  // predicted state example
  // px = 1, py = 2, vx = 0.2, vy = 0.4
  VectorXd x_predicted(4);
  x_predicted << 1, 2, 0.2, 0.4;

  MatrixXd Hj = CalculateJacobian(x_predicted);

  cout << "Hj:" << endl << Hj << endl;

  return 0;
}

MatrixXd CalculateJacobian(const VectorXd& x_state) {

  MatrixXd Hj(3,4);
  // recover state parameters
  float px = x_state(0);
  float py = x_state(1);
  float vx = x_state(2);
  float vy = x_state(3);

  // TODO: YOUR CODE HERE
  float px2 = px*px;
  float py2 = py*py;
  float pxpy = px*px + py*py;
  float rpxpy = sqrt(pxpy);
  float crpxpy = sqrt(pow(pxpy,3));

    // check division by zero
  if (fabs(pxpy) < 0.0001) {
    cout << "CalculateJacobian () - Error - Division by Zero" << endl;
    return Hj;
  }

  // compute the Jacobian matrix
  Hj << px/rpxpy , py/rpxpy, 0, 0,
        -py/pxpy, px/pxpy, 0, 0,
        py*(vx*py-vy*px)/crpxpy, px*(vy*px-vx*py)/crpxpy, px/rpxpy, py/rpxpy;

  return Hj;
}