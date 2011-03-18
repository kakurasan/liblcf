/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG.
//
// EasyRPG is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// EasyRPG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "lmu_reader.h"
#include "lmu_chunks.h"
#include "reader_lcf.h"
#include "reader_struct.h"

////////////////////////////////////////////////////////////
/// Read Event Page Condition
////////////////////////////////////////////////////////////
typedef RPG::EventPageCondition::Flags flags_type;

template <>
char const* const Flags<flags_type>::name("EventPageCondition_Flags");

template <>
const Flags<flags_type>::Flag* Flags<flags_type>::flags[] = {
	new Flags<flags_type>::Flag(&flags_type::switch_a,	"switch_a"	),
	new Flags<flags_type>::Flag(&flags_type::switch_b,	"switch_b"	),
	new Flags<flags_type>::Flag(&flags_type::variable,	"variable"	),
	new Flags<flags_type>::Flag(&flags_type::item,		"item"		),
	new Flags<flags_type>::Flag(&flags_type::actor,		"actor"		),
	new Flags<flags_type>::Flag(&flags_type::timer,		"timer"		),
	new Flags<flags_type>::Flag(&flags_type::timer2,	"timer2"	),
	NULL
};

template <>
const uint32_t Flags<flags_type>::max_size = 1;

EASYRPG_STRUCT_ID_READER(EventPageCondition, NoID)

EASYRPG_STRUCT_NAME(EventPageCondition)

#define EASYRPG_CHUNK_SUFFIX LMU_Reader
#define EASYRPG_CURRENT_STRUCT EventPageCondition

EASYRPG_STRUCT_FIELDS_BEGIN(EventPageCondition)
	EASYRPG_STRUCT_TYPED_FIELD(flags_type, flags),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_a_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_b_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, variable_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, variable_value),
	EASYRPG_STRUCT_TYPED_FIELD(int, item_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, actor_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, timer_sec),
	EASYRPG_STRUCT_TYPED_FIELD(int, timer2_sec),
	EASYRPG_STRUCT_TYPED_FIELD(int, compare_operator),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
