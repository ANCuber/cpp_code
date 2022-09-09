set nocompatible
set clipboard=unnamed


syn on
syn enable
let &t_8f="\<ESC>[38;2;%lu;%lu;%lum"
let &t_8b="\<ESC>[48;2;%lu;%lu;%lum"
set termguicolors
set enc=utf8
scriptencoding=utf8
set fileencoding=utf-8
set mouse=a
set ru rnu nu ai sta et
set ts=4 sts=4 sw=4 st=4 
set laststatus=2
set hlsearch incsearch
set showcmd

ino ( ()<ESC>i
ino [ []<ESC>i
ino ' ''<ESC>i
ino " ""<ESC>i
ino { {}<ESC>i
ino {<CR> {<CR>}<ESC>ko<TAB>
ino jk  <ESC>

map m $
map n ^

hi Normal guibg=NONE ctermbg=NONE
map <F5> :call RunCode()<CR>
map <TAB> i<TAB>


func! RunCode()
    exec 'w'
    if &filetype == 'cpp'
        exec '!g++ % -o %<.exe && echo "----owo----" && ./%<.exe'
    elseif &filetype == 'python'
        exec '!echo "----owo----" && python %'
    endif
endfunc

imap <F12> :r ~/cpp/setting.cpp<CR>ggdd13ji<TAB>
map <F12> :r ~/cpp/setting.cpp<CR>ggdd13ji<TAB>


