/// Iterate all subsets of a bitmask in increasing order

for ( int sub = 0 ; sub = sub - mask & mask ; ) {
  // do something
}

/// Iterate all subsets of a bitmask in decreasing order

for(int sub = (mask-1) & mask ; sub > 0 ; sub = (sub-1) & mask )  {
  // do something
}
