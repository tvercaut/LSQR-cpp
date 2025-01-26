# LSQR-cpp
This is a c++ port initially performed by Luis Ibanez of the LSQR library of Chris Paige and Michael Saunders. The same methodology was applied to the LSMR library of David Fong and Michael Saunders.

The LSQR library can be found here: http://web.stanford.edu/group/SOL/software/lsqr/ <br>
The LSMR library can be found here: http://web.stanford.edu/group/SOL/software/lsmr/

The original c++ port of LSQR could initially be found here (dead link?): http://svn.na-mic.org/NAMICSandBox/trunk/SparseLinearSolverConversion/

This work was performed to integrate it into the Insight Toolkit (ITK) - https://itk.org - and tracked with this original issue https://issues.itk.org/jira/browse/HISTITK-1160 (dead link?)

More recent relevant links:
- https://github.com/InsightSoftwareConsortium/ITK/tree/master/Modules/ThirdParty/VNL/src/vxl/v3p/netlib/linalg
- https://github.com/vxl/vxl/tree/master/v3p/netlib/linalg
- https://github.com/vxl/vxl/issues/332

--

LSQR and LSMR can solve sparse, dense and matrix-free linear equations and linear least-squares problems including damped least-squares.

--

The project uses `cmake` as a build process manager. Please have a look at the [cmake documentation](https://cmake.org/runningcmake/) for information on how to build a `cmake`-based project such as this one.
