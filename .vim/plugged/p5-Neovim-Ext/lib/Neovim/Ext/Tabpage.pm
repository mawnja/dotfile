package Neovim::Ext::Tabpage;

use strict;
use warnings;
use Carp qw/croak/;
use base qw/Neovim::Ext::Remote/;


sub new
{
	my ($this, $session, $code_data) = @_;

	return $this->SUPER::new ($session, 'nvim_tabpage_', $code_data);
}

=head1 NAME

Neovim::Ext::Tabpage - Neovim Tabpage class

=head1 SYNOPSIS

	use Neovim::Ext;

=cut

1;

