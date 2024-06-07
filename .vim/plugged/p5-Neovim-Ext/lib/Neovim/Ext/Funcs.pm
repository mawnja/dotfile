package Neovim::Ext::Funcs;

use strict;
use warnings;
use base qw/Class::Accessor/;

__PACKAGE__->mk_accessors (qw/nvim/);


sub new
{
	my ($this, $nvim) = @_;

	my $class = ref ($this) || $this;
	my $self =
	{
		nvim => $nvim,
	};

	return bless $self, $class;
}



sub DESTROY
{
}


our $AUTOLOAD;

sub AUTOLOAD
{
	my $methodName;
	($methodName = $AUTOLOAD) =~ s/.*:://;

	# Install
	no strict 'refs';
	*{$AUTOLOAD} = sub
	{
		my $this = shift;
		$this->nvim->call ($methodName, @_);
	};

	goto &$AUTOLOAD;
}

=head1 NAME

Neovim::Ext::Funcs - Neovim Funcs class

=head2 SYNOPSIS

	use Neovim::Ext;

	my $funcs = Neovim::Ext::Funcs->new ($nvim);

	# Call the vimscript 'join' function.
	# Produces 'first, last'
	my $out = $funcs->join (['first', 'last'], ', ');

=head2 DESCRIPTION

Helper package for functional vimscript interface. Methods are created on first use.

=cut

1;

