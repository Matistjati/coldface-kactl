syntax on
colorscheme elflord " or desert
set cursorline showmatch
set number relativenumber autoindent cindent
set expandtab softtabstop=2 smarttab shiftwidth=2
noremap <space> :
inoremap {<CR> {<CR>}<Esc>ko
inoremap (<CR> (<CR>)<Esc>ko
" Select region and then type :Hash to hash your selection.
" Useful for verifying that there aren't mistypes.
ca Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \
\| md5sum \| cut -c-6
