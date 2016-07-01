/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Language:  C++
  Date:      $Date: 2009-06-14 11:52:00 $
  Version:   $Revision: 1.69 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "lsqrDense.h"

#include <iostream>

#include <stdlib.h>
#include <math.h>


//
// A more interesting testing case, but still a basic one.
//
int lsqrTest2( int , char * [] )
{

  lsqrDense solver;

  const double eps = 1e-15;

  solver.SetOutputStream( std::cout );
  solver.SetEpsilon( eps );
  solver.SetDamp( 0.0 );
  solver.SetMaximumNumberOfIterations( 100 );
  solver.SetToleranceA( 1e-16 );
  solver.SetToleranceB( 1e-16 );
  solver.SetUpperLimitOnConditional( 1.0 / ( 10 * sqrt( eps ) ) );
  solver.SetStandardErrorEstimatesFlag( true );


  const unsigned int mm = 3;
  const unsigned int nn = 2;

  double bb[mm];
  double xx[nn];

  bb[0] = 7.0;
  bb[1] =-7.0;
  bb[2] = 2.0;

  solver.SetStandardErrorEstimatesFlag( true );
  double se[nn];

  solver.SetStandardErrorEstimates( se );

  //  -3  5
  typedef double * RowType;
  RowType A[mm];
  double AA[6];
  A[0] = &(AA[0]);
  A[1] = &(AA[2]);
  A[2] = &(AA[4]);
  A[0][0] = 1.0;
  A[0][1] = 2.0;
  A[1][0] = 4.0;
  A[1][1] = 1.0;
  A[2][0] = 1.0;
  A[2][1] = 1.0;
  solver.SetMatrix( A );

  solver.Solve( mm, nn, bb, xx );

  std::cout << "Stopped because " << solver.GetStoppingReason() << std::endl;
  std::cout << "Used " << solver.GetNumberOfIterationsPerformed() << " Iterations" << std::endl;
  std::cout << "Frobenius norm estimation of Abar = " << solver.GetFrobeniusNormEstimateOfAbar() << std::endl;
  std::cout << "Condition number estimation of Abar = " << solver.GetConditionNumberEstimateOfAbar() << std::endl;
  std::cout << "Estimate of final value of norm(rbar) = " << solver.GetFinalEstimateOfNormRbar() << std::endl;
  std::cout << "Estimate of final value of norm of residuals = " << solver.GetFinalEstimateOfNormOfResiduals() << std::endl;
  std::cout << "Estimate of norm of final solution = " << solver.GetFinalEstimateOfNormOfX() << std::endl;
  std::cout << "Solution = xx = " << xx[0] << " " << xx[1] << std::endl;

  return EXIT_SUCCESS;
}
