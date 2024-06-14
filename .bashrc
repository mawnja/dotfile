alias gs='git status'
alias gb='git branch'
alias gc='git checkout'
alias gp='git pull --rebase'

alias v="nvim"
alias l='cd /LocalRun/wenjian.ma'
alias tvm='cd /LocalRun/wenjian.ma/tvm'

export PATH=~/.vim/plugged/coc_extensions_install/clangd_11.0.0/bin:$PATH
export PATH=~/.vim/plugged/nvim-linux64_v0.9.5/bin:$PATH
export PATH=~/.vim/plugged/coc.nvim/bin:$PATH
export PATH=~/.vim/plugged/ripgrep/target/release:$PATH
export PATH=~/.vim/plugged/fd/target/release:$PATH
export PATH=~/.vim/plugged/node-v16.13.0-linux-x64/bin:$PATH
export PATH=~/.vim/plugged/tree-sitter/bin:$PATH
export PATH=~/.vim/plugged/perl-5.20.2/bin:$PATH
export PATH=~/.local/bin:$PATH
export PATH=~/.local/share/terminator:$PATH
export PATH=/usr/local/cuda/bin:$PATH
export PATH=/LocalRun/wenjian.ma/tmp/cmake-3.25.0-linux-x86_64/bin:$PATH
export PATH=/LocalRun/wenjian.ma/vscode/VSCode-linux-x64/bin:$PATH
export PATH=/LocalRun/wenjian.ma/myzsh/usr/bin:$PATH

export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=~/.vim/plugged/perl-5.20.2/lib:$LD_LIBRARY_PATH

export PYTHONPATH=/LocalRun/wenjian.ma/tvm/python:$PYTHONPATH

export TVM_BUILD_PATH=/LocalRun/wenjian.ma/tvm/build:$TVM_BUILD_PATH
export TVM_LIBRARY_PATH=/LocalRun/wenjian.ma/tvm/build:$TVM_LIBRARY_PATH
export TVM_LOG_DEBUG="ir/transform.cc=1;relay/ir/transform.cc=1"
. "$HOME/.cargo/env"

#[ -f ~/.fzf.bash ] && source ~/.fzf.bash
