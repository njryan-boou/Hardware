# hardwarey

A minimal C++17 project exposed to Python with pybind11. The example binding
reports the number of concurrent threads supported by the host CPU.

## Layout

```text
include/hardwarey/             Public C++ headers
src/                         C++ implementation and Python bindings
python/hardwarey/             Python package
tests/                       Python tests
```

## Build and install

Create and activate a virtual environment, then run:

```bash
python -m pip install --upgrade pip
python -m pip install -e .
```

To run the tests:

```bash
python -m pip install pytest
pytest
```

Run the example with:

```bash
python main.py
```
