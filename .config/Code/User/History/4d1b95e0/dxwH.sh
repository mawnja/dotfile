LOCAL=/LocalRun/wenjian.ma
TVM=${LOCAL}/tvm
BUILD=${TVM}/build

source ${LOCAL}/myenv/bin/activate

PYTEST="pytest -s -v --disable-warnings"
GDB_PYTEST="gdb --args python3 -m pytest -s -v --disable-warnings"

cd $BUILD && cmake .. && make -j4


#$PYTEST ${TVM}/tests/python/relay/test_any.py::test_any_conv2d
$PYTEST ${TVM}/tests/python/relay/test_any.py::test_TestAnyConv2dNCHWc
