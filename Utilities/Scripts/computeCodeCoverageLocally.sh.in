 #!/bin/csh
  make
  lcov --directory . --zerocounters 
  ~/local/bin/ctest
  lcov --directory . --capture --output-file app.info 
  lcov --extract app.info '*C++/Source*' --output-file lsqrCoverage.info
  genhtml lsqrCoverage.info 
  firefox ./index.html
