#!/bin/sh
export DYLD_FALLBACK_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES="libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@




# libft_malloc.so: code signing blocked mmap() of 'libft_malloc.so'