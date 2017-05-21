if [ ! -e '$HOME/goinfre' ] ; then
	    mkdir /goinfre/$(whoami)
	fi
	export PATH="$HOME"/goinfre/brew/bin:"$PATH"
	if [ ! -d '$HOME/goinfre/brew/bin' ] ; then
		    git clone https://github.com/Homebrew/homebrew.git ~/goinfre/brew
			    brew update
			fi 
