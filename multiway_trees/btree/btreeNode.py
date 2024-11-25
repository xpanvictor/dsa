
import typing

type K = any

class BTreeNode:
    pass


class BTreeNode:
    # priv
    _m: int
    children: list[BTreeNode]
    keys: list[K] # can store a specific type though
    isLeaf: bool
    parent: BTreeNode | None
    keyTally: int

    def __init__(self, m: int):
        self._m = m