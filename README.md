# cache-simulator

Computer Architecture - Final Cache-Simulator Assignment

![screensh](https://camo.githubusercontent.com/08b40541bb7affad34943fab21e7c1e32fa88c99930c775b7db2dbb9e92d0047/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f4c6963656e63652d4d49542d626c75652e737667)

This is a computer-architecture assignment implements a set associative cache simulator written in <code>C, Shell Script</code>. A set associative cache simulator Write policy is write-back and it follows LRU replacement strategy

### How to execute <code>test.sh</code>

---

1. check help manual

```
    $ ./{relative_path}/test.sh -h
    or
    $ (bash | sh) ${relative_path}/test.sh -h
    USAGE:
    test.sh [-s=<val>] [-b=<val>] [-a=<val>] [-d=<val>]
        [-h]

    DESCRIPTIONS:
    -s=<val>, s( cache_size ): total size of cache
    -b=<val>, b( block_size ): size of block
    -a=<val>, a( associative_size ): cache assocative size
    -d=<val>, d( dir_name ): tracefile set directory name
    -h, print usage
```

2. Simulate the tracefile

```
    $ ./{relative_path}/test.sh -s {cache_size} -b {block_size} -a {associative_size} -d {tracefile_directory}
```

- tracefile_direcyory
  ![screensh](./img/tracefile_dir.png)
  it must include varity type of trace file to simulate
