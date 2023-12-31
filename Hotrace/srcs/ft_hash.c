/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:12:40 by geargenc          #+#    #+#             */
/*   Updated: 2021/12/12 22:46:34 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static const uint64_t	g_k[] = {
	0x118fc350b7542469,
	0x9817d1d5414ec373,
	0x3771ef4fbbf04df7,
	0x4f3adf71f61eb7d3,
	0x00e519acbe527281,
	0x92999921a88d73ec,
	0x892ad9cd84103d45,
	0xb023be6b51d5d71d,
	0x997ec9ce56ba6257,
	0x51724c801976f0c8,
	0xd05cdb07710a5019,
	0xedc788cb45b2d5ed,
	0xc4283ace256e5803,
	0xd445c90dd480ee63,
	0xa090d5368adbb77e,
	0x0996d81e5b8411a7,
	0x9986781cdf4d2acd,
	0xa5401aecb03850b3,
	0x058474a18545150d,
	0x8c51c1dfb23d15fc,
	0x4864cc30989a8915,
	0x79dd3138268a077f,
	0x0523bd9c73adf6ee,
	0x26c84d98029ea918,
	0x0ee3bd3d14c9ce80,
	0x73a49e0a832e6144,
	0xc353afb8e166ddbc,
	0xc3736af95ca92e5c,
	0x64bf0300ac872e5b,
	0x036bf3fe82522444,
	0xf9e0f1e77368baa5,
	0x62edca5a8f794c14,
	0x6ee87e3d133a85d6,
	0x400bdd587325a210,
	0xbce77705d4c38953,
	0x52e0f28fd9314944,
	0x11dd289c96393b41,
	0xbb73f84228b65636,
	0xb2912c8057a9af67,
	0x777296ac523e3c8c,
	0xb4cf54851d50bee6,
	0x8f9aea1fd6d2e48e,
	0x3ab67c4cccb0a89f,
	0x0bb79deb515be4be,
	0x6be4acfc045972a3,
	0x4bf498563650d3be,
	0xcb5c45c5176c663b,
	0x7a217dbad7837e51,
	0x0558aa88b65ba202,
	0xc35fbc2e9228633e,
	0x46f2e2ce9f6d982c,
	0x69739959497a73a6,
	0x2c9f821d3f187d82,
	0xfa35072ab6b87c40,
	0xaafe4389c884cc43,
	0x3ad4d8db2011e046,
	0x5ce2811bdb27043e,
	0xc347332959f27179,
	0xb5a493cbef8932f1,
	0x3d5c20e8be722e84,
	0xced455c169b1dab8,
	0x38fbb982bf76c187,
	0x3ee249f1aa2c5b4d,
	0xe2819cf9d3c80c8b,
	0x972e74d192ecbc0c,
	0xb6f29495412c6bb6,
	0xfbebe59285e8586b,
	0xea89b87436e21a19,
	0x31e2106a90eadfce,
	0xe80fa7113798ad3d,
	0x2bf6cbb2a7a225f4,
	0x522730223a9664bd,
	0x6c57d5130c782fff,
	0xbf68e19af1b458c1,
	0x0c63f0ca4a62dd03,
	0xde7c82f8365b7d52,
	0x42799155dba9ef4e,
	0x3efdcaf6957a49a5,
	0xa121ce3560f230cc,
	0xfcd7f6a271604a1b,
	0xb7c82468b8f99a88,
	0x0c03464d8ab94123,
	0xb4a39149b1ebe0a2,
	0x00d780cd52fb7f65,
	0xdf7f4cbaedc9dff8,
	0x6df1b6a923cec0b5,
	0x9b42103d2b6406be,
	0xd55893f9bede4a28,
	0x2c8a008d761c9c57,
	0x324ed520ccd1a09e,
	0x3e0b6ddb6986dc20,
	0x28a1315abe4abb19,
	0x2c0c19dbba679514,
	0xe0d9b7873637fa42,
	0xc02fbc61a36d8f7e,
	0xc3512669e2875730,
	0x7d5dda5830330160,
	0x276a65b0c8827f0f,
	0xfade5bd149113230,
	0x8f59abd0f7022fd7,
	0x8028c301d27f504b,
	0x206b63b35ba31d5e,
	0x9e20c45b7e665a6f,
	0x6d9e2a953a4c8749,
	0x7ed2c07696b632b5,
	0x52bd631dd87af3c0,
	0x426465089c8ad356,
	0x63c5be976a179ba8,
	0x9dab0121395421b6,
	0xb5fbe89a4f8f67c8,
	0x4974d05658f89dca,
	0x71df456e3cf6fcc4,
	0xa009af9ab5e34d6a,
	0x945f730b60b6abc3,
	0xb94e9f778321ae45,
	0xdc7e6f59a2abf1d5,
	0x35d314e4bb851cfd,
	0xf051f8c2c7efafa1,
	0x524ecc63bee029ef,
	0xa9719aefee42bdf9,
	0x97223d190714c088,
	0xef46cc2380933af2,
	0x2ab6d34cdeb15efb,
	0x9e42ad1410dfc4cd,
	0xa832aebe7d210b5c,
	0x540d2e1474364fa4,
	0x4ff45797d254bf60,
	0x1e1e50179e5631c3,
	0x79a05196daa4545d,
	0xfe82a81cfb0d7fd1,
	0x4cde63e472b432bb,
	0xe5ccf5333aba391a,
	0x2ab07926f30170f0,
	0x5f4ac72eeefd88df,
	0x4eb49625cd36c1b3,
	0x1978dde9028125a6,
	0x75dc4579dbfe623a,
	0xaa68069c6abfed2e,
	0xf25332ffeef159f4,
	0x52fa96d03139fbea,
	0x6ac79a8960aaa350,
	0x91581fa41d94b190,
	0xebde555a49db79ad,
	0x23a50e11d4c98cf5,
	0x2ecb5fd9d7f24b1b,
	0xd419c7119f46735b,
	0x7c4c17189bde1eeb,
	0xa4afec6ed8cc12d4,
	0x00c8485f56d69233,
	0x700d111c44e97f31,
	0x3c620d67237af175,
	0x0b627c0d2bf8cf6b,
	0x2b6cf4b9e61f2863,
	0x725dd7f8723c3093,
	0x180fc35d2cc1e011,
	0xa9444be45eb0f946,
	0x1df774d4980572c2,
	0x6d8a72b1755c293e,
	0x577d291ee2231d19,
	0x6d74b2a867aff74d,
	0xcad958eb4e2b688f,
	0x5dc9e7bbfb641cda,
	0x8ea5b2301640383e,
	0x6b206da1f33f8b8d,
	0xac56e6b9ffa61889,
	0x205e4bbd0feba44b,
	0xecca90deea70fe2e,
	0x9f7878eba2ae5d3d,
	0x7fe212ec170f5d2c,
	0xbd718a3cddbdf093,
	0x97c1feb766b0e7f9,
	0x54eec54b848b7a9e,
	0xb5c9ff4638afb68b,
	0x4b00c8ca4013a35c,
	0xded3cf584915a01b,
	0x59bd17fc5afb19b0,
	0x4cb2292b1e23c49d,
	0x18e62d3cf8825182,
	0xb8cc8888b6af0001,
	0x617bf85709ed1625,
	0xd812cde8818d1b7b,
	0xf02d1f662f5323f6,
	0x5fef9dc4ab2ccc80,
	0x00c936f104d441c3,
	0xe2d1307bce87ec9a,
	0xa00d2a5b15479786,
	0x90fb931704e4a5ed,
	0x0548bc359fcb2147,
	0xf8f99e536b848dbc,
	0x53fc43e48ff6e11a,
	0x7143c50ad48cca11,
	0xe701c60c4d35512d,
	0xfa7da550856085ff,
	0x018cc8ae3da970b3,
	0x8cce7680ce314948,
	0x01478958fc0118c4,
	0x3f01f5a26e97663a,
	0x6870c788e81802ce,
	0x3dbe9ae0ef411e9e,
	0xfd238c7a35a0a004,
	0x0900ecac188f0311,
	0x8f39f5f113954b32,
	0x6edc04bd1e0a95bf,
	0xf253cd9e9de5dfc5,
	0x07543346d057ab3a,
	0x4dc0cdfc77001e11,
	0x29900424694d0337,
	0xc40a2c07043864b4,
	0xf6b93d1ecce7af42,
	0x5297ac836692e39f,
	0xf462973be1412a0f,
	0x9b71313e743bbf0f,
	0xf6b883a56388942b,
	0xb7f0f91012981660,
	0x77509315b923ebb8,
	0x2e67764fb980b421,
	0x9a06b0f9f88ee3e2,
	0x9d5c51421b45f08a,
	0x266bc06fc73b4d7e,
	0x851689e151efe257,
	0xca02c3f7ad87f770,
	0xa866a530f262d6d9,
	0x97d740ef89d03b63,
	0x0bfa7eb9f7515e27,
	0x55a6aed6db74b9f5,
	0x893f5ee98e3e1649,
	0x324709a61aad8ffa,
	0x2c6eaa3a27b97edb,
	0x064e1345220ab14d,
	0x02c9f493ca816cd6,
	0x68ea92518cec3627,
	0x5b4f0c5bc83b7b1b,
	0x2c32d66e7ff67dd2,
	0x5a2455a08d49e019,
	0x0685ac8ef382eb70,
	0x64a3482d9cd1e4fc,
	0xe62eb779f7009df5,
	0x92e390ee3244a10a,
	0x7de40b96216a9b6b,
	0xfbf8f9b4a2e70782,
	0x7ca3ccec3f081ba2,
	0x0275106d92ee410a,
	0x8086a84fda8ca9db,
	0xed9f2b1ba8b4b025,
	0xa51db1b22b005749,
	0x883d6b04983fb568,
	0x70969e78d53538b1,
	0x16099410e79f091f,
	0xe9c7c7bc47380ac0,
	0xcd3d5ed0ba7a6244,
	0xa08b2945690b2593,
	0x20848780ccf6f4cd,
	0xbbc42143fdd63dbc,
	0xaa60d7dcbc31e4ec,
	0x9985ea10a3c6cf04,
	0x6077a910ec4c00da
};

uint64_t	hashfunc(char *str)
{
	uint64_t			v;

	v = 0x7213701e0c00376d;
	while (*str)
	{
		v ^= g_k[*(unsigned char *)str];
		++str;
	}
	return (v);
}

int	ft_strequ(char *s1, char *s2)
{
	unsigned long	*ls1;
	unsigned long	*ls2;
	unsigned long	v;
	unsigned long	v2;

	ls1 = (unsigned long *)s1;
	ls2 = (unsigned long *)s2;
	v = *ls1;
	v = ~((((v & MASK_0X7F) + MASK_0X7F) | v) | MASK_0X7F);
	v2 = *ls1 ^ *ls2;
	while (!(v || v2))
	{
		++ls1;
		++ls2;
		v = *ls1;
		v = ~((((*ls1 & MASK_0X7F) + MASK_0X7F) | *ls1) | MASK_0X7F);
		v2 = *ls1 ^ *ls2;
	}
	v = (v ^ (v & (v - 1))) - 1;
	v2 = (v2 ^ (v2 & (v2 - 1))) - 1;
	if (v2 <= v)
		return (0);
	return (1);
}
