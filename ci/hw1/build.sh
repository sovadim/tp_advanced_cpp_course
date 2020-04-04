# Build process lib
mkdir -p hw1/processlib/build
cd hw1/processlib/build
cmake ..
make
cd ../../..

# Build samples
mkdir -p hw1/samples/echo-server/build
cd hw1/samples/echo-server/build
cmake ..
make
cd ../../../..
