# Build process lib
mkdir -p hw1_processlib/processlib/build
cd hw1_processlib/processlib/build
cmake ..
make
cd ../../..

# Build samples
mkdir -p hw1_processlib/samples/echo-server/build
cd hw1_processlib/samples/echo-server/build
cmake ..
make
cd ../../../..
