package Neovim::Ext::Common;

use strict;
use warnings;
use Exporter 'import';

our @EXPORT_OK = qw/walk/;


sub walk
{
	my ($sub, $obj, @args) = @_;

	if (ref ($obj) eq 'ARRAY')
	{
		return [map { walk ($sub, $_, @args) } @$obj];
	}

	if (ref ($obj) eq 'HASH')
	{
		my %result;
		while (my ($key, $value) = each %$obj)
		{
			$result{walk ($sub, $key, @args)} = walk ($sub, $value, @args);
		}

		return \%result;
	}

	return $sub->($obj, @args);
}

=head1 NAME

Neovim::Ext::Common - Common functions

=head1 FUNCTIONS

=head2 walk( \&sub, $obj, @args)

Walk C<$obj> recursively, calling C<\&sub> with C<$obj> and C<@args>.

=cut

1;

