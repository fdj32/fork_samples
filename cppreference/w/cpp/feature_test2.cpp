
 static constexpr struct change_these_options_to_select_what_will_be_printed
{
    constexpr static int longest_macro_name { 44 };
    constexpr static bool titles               = 1;
    constexpr static bool counters             = 1;
    constexpr static bool attributes           = 1;
    constexpr static bool general_features     = 1;
    constexpr static bool core_features        = 1;
    constexpr static bool lib_features         = 1;
    constexpr static bool supported_features   = 1;
    constexpr static bool unsupported_features = 1;
    constexpr static bool sort_by_date         = 0;
    constexpr static bool separate_year_month  = 1;
    constexpr static bool separated_revisions  = 1;
    constexpr static bool latest_revisions     = 1;
    constexpr static bool cxx11                = 1;
    constexpr static bool cxx14                = 1;
    constexpr static bool cxx17                = 1;
    constexpr static bool cxx20                = 1;
    constexpr static bool cxx23                = 1;
    constexpr static bool cxx26                = 0;
} print;

#if __cplusplus < 201100
#  error "C++11 or better is required"
#endif

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <utility>
#include <vector>

#ifdef __has_include
# if __has_include(<version>)
#   include <version>
# endif
#endif

#define COMPILER_FEATURE_VALUE(value) #value
#define COMPILER_FEATURE_ENTRY(name) { #name, COMPILER_FEATURE_VALUE(name) },

#ifdef __has_cpp_attribute
# define COMPILER_ATTRIBUTE_VALUE_AS_STRING(s) #s
# define COMPILER_ATTRIBUTE_AS_NUMBER(x) COMPILER_ATTRIBUTE_VALUE_AS_STRING(x)
# define COMPILER_ATTRIBUTE_ENTRY(attr) \
{ #attr, COMPILER_ATTRIBUTE_AS_NUMBER(__has_cpp_attribute(attr)) },
#else
# define COMPILER_ATTRIBUTE_ENTRY(attr) { #attr, "_" },
#endif

typedef std::pair<char const*, char const*> CompilerFeature; // {name, value}

static constexpr CompilerFeature cxx_core[] = {
    COMPILER_FEATURE_ENTRY(__cplusplus)
    COMPILER_FEATURE_ENTRY(__cpp_exceptions)
    COMPILER_FEATURE_ENTRY(__cpp_rtti)
#if 0
    COMPILER_FEATURE_ENTRY(__GNUC__)
    COMPILER_FEATURE_ENTRY(__GNUC_MINOR__)
    COMPILER_FEATURE_ENTRY(__GNUC_PATCHLEVEL__)
    COMPILER_FEATURE_ENTRY(__GNUG__)
    COMPILER_FEATURE_ENTRY(__clang__)
    COMPILER_FEATURE_ENTRY(__clang_major__)
    COMPILER_FEATURE_ENTRY(__clang_minor__)
    COMPILER_FEATURE_ENTRY(__clang_patchlevel__)
#endif
};
static constexpr CompilerFeature cxx11_core[] = {
    COMPILER_FEATURE_ENTRY(__cpp_alias_templates)
    COMPILER_FEATURE_ENTRY(__cpp_attributes)
    COMPILER_FEATURE_ENTRY(__cpp_constexpr)
    COMPILER_FEATURE_ENTRY(__cpp_decltype)
    COMPILER_FEATURE_ENTRY(__cpp_delegating_constructors)
    COMPILER_FEATURE_ENTRY(__cpp_inheriting_constructors)
    COMPILER_FEATURE_ENTRY(__cpp_initializer_lists)
    COMPILER_FEATURE_ENTRY(__cpp_lambdas)
    COMPILER_FEATURE_ENTRY(__cpp_nsdmi)
    COMPILER_FEATURE_ENTRY(__cpp_range_based_for)
    COMPILER_FEATURE_ENTRY(__cpp_raw_strings)
    COMPILER_FEATURE_ENTRY(__cpp_ref_qualifiers)
    COMPILER_FEATURE_ENTRY(__cpp_rvalue_references)
    COMPILER_FEATURE_ENTRY(__cpp_static_assert)
    COMPILER_FEATURE_ENTRY(__cpp_threadsafe_static_init)
    COMPILER_FEATURE_ENTRY(__cpp_unicode_characters)
    COMPILER_FEATURE_ENTRY(__cpp_unicode_literals)
    COMPILER_FEATURE_ENTRY(__cpp_user_defined_literals)
    COMPILER_FEATURE_ENTRY(__cpp_variadic_templates)
};
static constexpr CompilerFeature cxx14_core[] = {
    COMPILER_FEATURE_ENTRY(__cpp_aggregate_nsdmi)
    COMPILER_FEATURE_ENTRY(__cpp_binary_literals)
    COMPILER_FEATURE_ENTRY(__cpp_constexpr)
    COMPILER_FEATURE_ENTRY(__cpp_decltype_auto)
    COMPILER_FEATURE_ENTRY(__cpp_generic_lambdas)
    COMPILER_FEATURE_ENTRY(__cpp_init_captures)
    COMPILER_FEATURE_ENTRY(__cpp_return_type_deduction)
    COMPILER_FEATURE_ENTRY(__cpp_sized_deallocation)
    COMPILER_FEATURE_ENTRY(__cpp_variable_templates)
};
static constexpr CompilerFeature cxx14_lib[] = {
    COMPILER_FEATURE_ENTRY(__cpp_lib_chrono_udls)
    COMPILER_FEATURE_ENTRY(__cpp_lib_complex_udls)
    COMPILER_FEATURE_ENTRY(__cpp_lib_exchange_function)
    COMPILER_FEATURE_ENTRY(__cpp_lib_generic_associative_lookup)
    COMPILER_FEATURE_ENTRY(__cpp_lib_integer_sequence)
    COMPILER_FEATURE_ENTRY(__cpp_lib_integral_constant_callable)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_final)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_null_pointer)
    COMPILER_FEATURE_ENTRY(__cpp_lib_make_reverse_iterator)
    COMPILER_FEATURE_ENTRY(__cpp_lib_make_unique)
    COMPILER_FEATURE_ENTRY(__cpp_lib_null_iterators)
    COMPILER_FEATURE_ENTRY(__cpp_lib_quoted_string_io)
    COMPILER_FEATURE_ENTRY(__cpp_lib_result_of_sfinae)
    COMPILER_FEATURE_ENTRY(__cpp_lib_robust_nonmodifying_seq_ops)
    COMPILER_FEATURE_ENTRY(__cpp_lib_shared_timed_mutex)
    COMPILER_FEATURE_ENTRY(__cpp_lib_string_udls)
    COMPILER_FEATURE_ENTRY(__cpp_lib_transformation_trait_aliases)
    COMPILER_FEATURE_ENTRY(__cpp_lib_transparent_operators)
    COMPILER_FEATURE_ENTRY(__cpp_lib_tuple_element_t)
    COMPILER_FEATURE_ENTRY(__cpp_lib_tuples_by_type)
};

static constexpr CompilerFeature cxx17_core[] = {
    COMPILER_FEATURE_ENTRY(__cpp_aggregate_bases)
    COMPILER_FEATURE_ENTRY(__cpp_aligned_new)
    COMPILER_FEATURE_ENTRY(__cpp_capture_star_this)
    COMPILER_FEATURE_ENTRY(__cpp_constexpr)
    COMPILER_FEATURE_ENTRY(__cpp_deduction_guides)
    COMPILER_FEATURE_ENTRY(__cpp_enumerator_attributes)
    COMPILER_FEATURE_ENTRY(__cpp_fold_expressions)
    COMPILER_FEATURE_ENTRY(__cpp_guaranteed_copy_elision)
    COMPILER_FEATURE_ENTRY(__cpp_hex_float)
    COMPILER_FEATURE_ENTRY(__cpp_if_constexpr)
    COMPILER_FEATURE_ENTRY(__cpp_inheriting_constructors)
    COMPILER_FEATURE_ENTRY(__cpp_inline_variables)
    COMPILER_FEATURE_ENTRY(__cpp_namespace_attributes)
    COMPILER_FEATURE_ENTRY(__cpp_noexcept_function_type)
    COMPILER_FEATURE_ENTRY(__cpp_nontype_template_args)
    COMPILER_FEATURE_ENTRY(__cpp_nontype_template_parameter_auto)
    COMPILER_FEATURE_ENTRY(__cpp_range_based_for)
    COMPILER_FEATURE_ENTRY(__cpp_static_assert)
    COMPILER_FEATURE_ENTRY(__cpp_structured_bindings)
    COMPILER_FEATURE_ENTRY(__cpp_template_template_args)
    COMPILER_FEATURE_ENTRY(__cpp_variadic_using)
};
static constexpr CompilerFeature cxx17_lib[] = {
    COMPILER_FEATURE_ENTRY(__cpp_lib_addressof_constexpr)
    COMPILER_FEATURE_ENTRY(__cpp_lib_allocator_traits_is_always_equal)
    COMPILER_FEATURE_ENTRY(__cpp_lib_any)
    COMPILER_FEATURE_ENTRY(__cpp_lib_apply)
    COMPILER_FEATURE_ENTRY(__cpp_lib_array_constexpr)
    COMPILER_FEATURE_ENTRY(__cpp_lib_as_const)
    COMPILER_FEATURE_ENTRY(__cpp_lib_atomic_is_always_lock_free)
    COMPILER_FEATURE_ENTRY(__cpp_lib_bool_constant)
    COMPILER_FEATURE_ENTRY(__cpp_lib_boyer_moore_searcher)
    COMPILER_FEATURE_ENTRY(__cpp_lib_byte)
    COMPILER_FEATURE_ENTRY(__cpp_lib_chrono)
    COMPILER_FEATURE_ENTRY(__cpp_lib_clamp)
    COMPILER_FEATURE_ENTRY(__cpp_lib_enable_shared_from_this)
    COMPILER_FEATURE_ENTRY(__cpp_lib_execution)
    COMPILER_FEATURE_ENTRY(__cpp_lib_filesystem)
    COMPILER_FEATURE_ENTRY(__cpp_lib_gcd_lcm)
    COMPILER_FEATURE_ENTRY(__cpp_lib_hardware_interference_size)
    COMPILER_FEATURE_ENTRY(__cpp_lib_has_unique_object_representations)
    COMPILER_FEATURE_ENTRY(__cpp_lib_hypot)
    COMPILER_FEATURE_ENTRY(__cpp_lib_incomplete_container_elements)
    COMPILER_FEATURE_ENTRY(__cpp_lib_invoke)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_aggregate)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_invocable)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_swappable)
    COMPILER_FEATURE_ENTRY(__cpp_lib_launder)
    COMPILER_FEATURE_ENTRY(__cpp_lib_logical_traits)
    COMPILER_FEATURE_ENTRY(__cpp_lib_make_from_tuple)
    COMPILER_FEATURE_ENTRY(__cpp_lib_map_try_emplace)
    COMPILER_FEATURE_ENTRY(__cpp_lib_math_special_functions)
    COMPILER_FEATURE_ENTRY(__cpp_lib_memory_resource)
    COMPILER_FEATURE_ENTRY(__cpp_lib_node_extract)
    COMPILER_FEATURE_ENTRY(__cpp_lib_nonmember_container_access)
    COMPILER_FEATURE_ENTRY(__cpp_lib_not_fn)
    COMPILER_FEATURE_ENTRY(__cpp_lib_optional)
    COMPILER_FEATURE_ENTRY(__cpp_lib_parallel_algorithm)
    COMPILER_FEATURE_ENTRY(__cpp_lib_raw_memory_algorithms)
    COMPILER_FEATURE_ENTRY(__cpp_lib_sample)
    COMPILER_FEATURE_ENTRY(__cpp_lib_scoped_lock)
    COMPILER_FEATURE_ENTRY(__cpp_lib_shared_mutex)
    COMPILER_FEATURE_ENTRY(__cpp_lib_shared_ptr_arrays)
    COMPILER_FEATURE_ENTRY(__cpp_lib_shared_ptr_weak_type)
    COMPILER_FEATURE_ENTRY(__cpp_lib_string_view)
    COMPILER_FEATURE_ENTRY(__cpp_lib_to_chars)
    COMPILER_FEATURE_ENTRY(__cpp_lib_transparent_operators)
    COMPILER_FEATURE_ENTRY(__cpp_lib_type_trait_variable_templates)
    COMPILER_FEATURE_ENTRY(__cpp_lib_uncaught_exceptions)
    COMPILER_FEATURE_ENTRY(__cpp_lib_unordered_map_try_emplace)
    COMPILER_FEATURE_ENTRY(__cpp_lib_variant)
    COMPILER_FEATURE_ENTRY(__cpp_lib_void_t)
};

static constexpr CompilerFeature cxx20_core[] = {
    COMPILER_FEATURE_ENTRY(__cpp_aggregate_paren_init)
    COMPILER_FEATURE_ENTRY(__cpp_char8_t)
    COMPILER_FEATURE_ENTRY(__cpp_concepts)
    COMPILER_FEATURE_ENTRY(__cpp_conditional_explicit)
    COMPILER_FEATURE_ENTRY(__cpp_consteval)
    COMPILER_FEATURE_ENTRY(__cpp_constexpr)
    COMPILER_FEATURE_ENTRY(__cpp_constexpr_dynamic_alloc)
    COMPILER_FEATURE_ENTRY(__cpp_constexpr_in_decltype)
    COMPILER_FEATURE_ENTRY(__cpp_constinit)
    COMPILER_FEATURE_ENTRY(__cpp_deduction_guides)
    COMPILER_FEATURE_ENTRY(__cpp_designated_initializers)
    COMPILER_FEATURE_ENTRY(__cpp_generic_lambdas)
    COMPILER_FEATURE_ENTRY(__cpp_impl_coroutine)
    COMPILER_FEATURE_ENTRY(__cpp_impl_destroying_delete)
    COMPILER_FEATURE_ENTRY(__cpp_impl_three_way_comparison)
    COMPILER_FEATURE_ENTRY(__cpp_init_captures)
    COMPILER_FEATURE_ENTRY(__cpp_modules)
    COMPILER_FEATURE_ENTRY(__cpp_nontype_template_args)
    COMPILER_FEATURE_ENTRY(__cpp_using_enum)
};
static constexpr CompilerFeature cxx20_lib[] = {
    COMPILER_FEATURE_ENTRY(__cpp_lib_array_constexpr)
    COMPILER_FEATURE_ENTRY(__cpp_lib_assume_aligned)
    COMPILER_FEATURE_ENTRY(__cpp_lib_atomic_flag_test)
    COMPILER_FEATURE_ENTRY(__cpp_lib_atomic_float)
    COMPILER_FEATURE_ENTRY(__cpp_lib_atomic_lock_free_type_aliases)
    COMPILER_FEATURE_ENTRY(__cpp_lib_atomic_ref)
    COMPILER_FEATURE_ENTRY(__cpp_lib_atomic_shared_ptr)
    COMPILER_FEATURE_ENTRY(__cpp_lib_atomic_value_initialization)
    COMPILER_FEATURE_ENTRY(__cpp_lib_atomic_wait)
    COMPILER_FEATURE_ENTRY(__cpp_lib_barrier)
    COMPILER_FEATURE_ENTRY(__cpp_lib_bind_front)
    COMPILER_FEATURE_ENTRY(__cpp_lib_bit_cast)
    COMPILER_FEATURE_ENTRY(__cpp_lib_bitops)
    COMPILER_FEATURE_ENTRY(__cpp_lib_bounded_array_traits)
    COMPILER_FEATURE_ENTRY(__cpp_lib_char8_t)
    COMPILER_FEATURE_ENTRY(__cpp_lib_chrono)
    COMPILER_FEATURE_ENTRY(__cpp_lib_concepts)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_algorithms)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_complex)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_dynamic_alloc)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_functional)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_iterator)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_memory)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_numeric)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_string)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_string_view)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_tuple)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_utility)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_vector)
    COMPILER_FEATURE_ENTRY(__cpp_lib_coroutine)
    COMPILER_FEATURE_ENTRY(__cpp_lib_destroying_delete)
    COMPILER_FEATURE_ENTRY(__cpp_lib_endian)
    COMPILER_FEATURE_ENTRY(__cpp_lib_erase_if)
    COMPILER_FEATURE_ENTRY(__cpp_lib_execution)
    COMPILER_FEATURE_ENTRY(__cpp_lib_format)
    COMPILER_FEATURE_ENTRY(__cpp_lib_generic_unordered_lookup)
    COMPILER_FEATURE_ENTRY(__cpp_lib_int_pow2)
    COMPILER_FEATURE_ENTRY(__cpp_lib_integer_comparison_functions)
    COMPILER_FEATURE_ENTRY(__cpp_lib_interpolate)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_constant_evaluated)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_layout_compatible)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_nothrow_convertible)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_pointer_interconvertible)
    COMPILER_FEATURE_ENTRY(__cpp_lib_jthread)
    COMPILER_FEATURE_ENTRY(__cpp_lib_latch)
    COMPILER_FEATURE_ENTRY(__cpp_lib_list_remove_return_type)
    COMPILER_FEATURE_ENTRY(__cpp_lib_math_constants)
    COMPILER_FEATURE_ENTRY(__cpp_lib_polymorphic_allocator)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges)
    COMPILER_FEATURE_ENTRY(__cpp_lib_remove_cvref)
    COMPILER_FEATURE_ENTRY(__cpp_lib_semaphore)
    COMPILER_FEATURE_ENTRY(__cpp_lib_shared_ptr_arrays)
    COMPILER_FEATURE_ENTRY(__cpp_lib_shift)
    COMPILER_FEATURE_ENTRY(__cpp_lib_smart_ptr_for_overwrite)
    COMPILER_FEATURE_ENTRY(__cpp_lib_source_location)
    COMPILER_FEATURE_ENTRY(__cpp_lib_span)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ssize)
    COMPILER_FEATURE_ENTRY(__cpp_lib_starts_ends_with)
    COMPILER_FEATURE_ENTRY(__cpp_lib_string_view)
    COMPILER_FEATURE_ENTRY(__cpp_lib_syncbuf)
    COMPILER_FEATURE_ENTRY(__cpp_lib_three_way_comparison)
    COMPILER_FEATURE_ENTRY(__cpp_lib_to_address)
    COMPILER_FEATURE_ENTRY(__cpp_lib_to_array)
    COMPILER_FEATURE_ENTRY(__cpp_lib_type_identity)
    COMPILER_FEATURE_ENTRY(__cpp_lib_unwrap_ref)
};

static constexpr CompilerFeature cxx23_core[] = {
    //< Continue to Populate
    COMPILER_FEATURE_ENTRY(__cpp_char8_t)
    COMPILER_FEATURE_ENTRY(__cpp_concepts)
    COMPILER_FEATURE_ENTRY(__cpp_consteval)
    COMPILER_FEATURE_ENTRY(__cpp_constexpr)
    COMPILER_FEATURE_ENTRY(__cpp_explicit_this_parameter)
    COMPILER_FEATURE_ENTRY(__cpp_if_consteval)
    COMPILER_FEATURE_ENTRY(__cpp_implicit_move)
    COMPILER_FEATURE_ENTRY(__cpp_multidimensional_subscript)
    COMPILER_FEATURE_ENTRY(__cpp_named_character_escapes)
    COMPILER_FEATURE_ENTRY(__cpp_size_t_suffix)
    COMPILER_FEATURE_ENTRY(__cpp_static_call_operator)
};
static constexpr CompilerFeature cxx23_lib[] = {
    //< Continue to Populate
    COMPILER_FEATURE_ENTRY(__cpp_lib_adaptor_iterator_pair_constructor)
    COMPILER_FEATURE_ENTRY(__cpp_lib_algorithm_iterator_requirements)
    COMPILER_FEATURE_ENTRY(__cpp_lib_allocate_at_least)
    COMPILER_FEATURE_ENTRY(__cpp_lib_associative_heterogeneous_erasure)
    COMPILER_FEATURE_ENTRY(__cpp_lib_bind_back)
    COMPILER_FEATURE_ENTRY(__cpp_lib_byteswap)
    COMPILER_FEATURE_ENTRY(__cpp_lib_concepts)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_bitset)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_charconv)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_cmath)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_memory)
    COMPILER_FEATURE_ENTRY(__cpp_lib_constexpr_typeinfo)
    COMPILER_FEATURE_ENTRY(__cpp_lib_containers_ranges)
    COMPILER_FEATURE_ENTRY(__cpp_lib_expected)
    COMPILER_FEATURE_ENTRY(__cpp_lib_find_last)
    COMPILER_FEATURE_ENTRY(__cpp_lib_flat_map)
    COMPILER_FEATURE_ENTRY(__cpp_lib_flat_set)
    COMPILER_FEATURE_ENTRY(__cpp_lib_format)
    COMPILER_FEATURE_ENTRY(__cpp_lib_format_ranges)
    COMPILER_FEATURE_ENTRY(__cpp_lib_forward_like)
    COMPILER_FEATURE_ENTRY(__cpp_lib_generator)
    COMPILER_FEATURE_ENTRY(__cpp_lib_invoke_r)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ios_noreplace)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_implicit_lifetime)
    COMPILER_FEATURE_ENTRY(__cpp_lib_is_scoped_enum)
    COMPILER_FEATURE_ENTRY(__cpp_lib_mdspan)
    COMPILER_FEATURE_ENTRY(__cpp_lib_modules)
    COMPILER_FEATURE_ENTRY(__cpp_lib_move_iterator_concept)
    COMPILER_FEATURE_ENTRY(__cpp_lib_move_only_function)
    COMPILER_FEATURE_ENTRY(__cpp_lib_optional)
    COMPILER_FEATURE_ENTRY(__cpp_lib_out_ptr)
    COMPILER_FEATURE_ENTRY(__cpp_lib_print)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_as_const)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_as_rvalue)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_cartesian_product)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_chunk)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_chunk_by)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_contains)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_fold)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_iota)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_join_with)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_repeat)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_slide)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_starts_ends_with)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_stride)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_to_container)
    COMPILER_FEATURE_ENTRY(__cpp_lib_ranges_zip)
    COMPILER_FEATURE_ENTRY(__cpp_lib_reference_from_temporary)
    COMPILER_FEATURE_ENTRY(__cpp_lib_shift)
    COMPILER_FEATURE_ENTRY(__cpp_lib_spanstream)
    COMPILER_FEATURE_ENTRY(__cpp_lib_stacktrace)
    COMPILER_FEATURE_ENTRY(__cpp_lib_start_lifetime_as)
    COMPILER_FEATURE_ENTRY(__cpp_lib_stdatomic_h)
    COMPILER_FEATURE_ENTRY(__cpp_lib_string_contains)
    COMPILER_FEATURE_ENTRY(__cpp_lib_string_resize_and_overwrite)
    COMPILER_FEATURE_ENTRY(__cpp_lib_to_underlying)
    COMPILER_FEATURE_ENTRY(__cpp_lib_tuple_like)
    COMPILER_FEATURE_ENTRY(__cpp_lib_unreachable)
    COMPILER_FEATURE_ENTRY(__cpp_lib_variant)
};

static constexpr CompilerFeature cxx26_core[] = {
    //< Populate
    COMPILER_FEATURE_ENTRY(__cpp_core_TODO)
};
static constexpr CompilerFeature cxx26_lib[] = {
    //< Populate
    COMPILER_FEATURE_ENTRY(__cpp_lib_TODO)
};

static constexpr CompilerFeature attributes[] = {
    COMPILER_ATTRIBUTE_ENTRY(assume)
    COMPILER_ATTRIBUTE_ENTRY(carries_dependency)
    COMPILER_ATTRIBUTE_ENTRY(deprecated)
    COMPILER_ATTRIBUTE_ENTRY(fallthrough)
    COMPILER_ATTRIBUTE_ENTRY(likely)
    COMPILER_ATTRIBUTE_ENTRY(maybe_unused)
    COMPILER_ATTRIBUTE_ENTRY(nodiscard)
    COMPILER_ATTRIBUTE_ENTRY(noreturn)
    COMPILER_ATTRIBUTE_ENTRY(no_unique_address)
    COMPILER_ATTRIBUTE_ENTRY(unlikely)
};

constexpr bool is_feature_supported(const CompilerFeature& x)
{
    return x.second[0] != '_' && x.second[0] != '0';
}

inline void print_compiler_feature(const CompilerFeature& x)
{
    std::string value{ is_feature_supported(x) ? x.second : "------" };
    if (value.back() == 'L') // e.g. 201603L -> 201603
        value.pop_back();
    if (print.separate_year_month) // e.g. 201603 -> 2016-03
        value.insert(4, 1, '-');
    if ((print.supported_features && is_feature_supported(x))
        or (print.unsupported_features && !is_feature_supported(x)))
        std::printf("%*s%s\n", -print.longest_macro_name, x.first, value.c_str());
}

template<class Container>
inline void show(char const* title, Container const& co)
{
    if (print.titles)
    {
        std::printf("%-s (", title);
        if (print.counters)
            std::printf("%ld/", std::count_if(std::begin(co), std::end(co),
                                              is_feature_supported));
        std::printf("%td)\n", std::distance(std::begin(co), std::end(co)));
    }
    if (print.sort_by_date)
    {
        std::vector<CompilerFeature> v(std::begin(co), std::end(co));
        std::stable_sort(v.begin(), v.end(),
            [](CompilerFeature const& lhs, CompilerFeature const& rhs) {
                return std::strcmp(lhs.second, rhs.second) < 0;
            });
        std::for_each(v.cbegin(), v.cend(), print_compiler_feature);
    }
    else
        std::for_each(std::begin(co), std::end(co), print_compiler_feature);
    std::puts("");
}

inline int latest_rev()
{
    int rev{3};
    if (print.cxx11) rev = 11;
    if (print.cxx14) rev = 14;
    if (print.cxx17) rev = 17;
    if (print.cxx20) rev = 20;
    if (print.cxx23) rev = 23;
    if (print.cxx26) rev = 26;
    return rev;
}

inline void show_latest()
{
    struct Cmp {
        bool operator()(const char* x, const char* y) const { return std::strcmp(x, y) < 0; }
    };
    std::map<char const*, char const*, Cmp> latest;
    char text[64];
    if (print.core_features)
    {   // keep reverse revision insersion order!
        if (print.cxx26) latest.insert(std::begin(cxx26_core), std::end(cxx26_core));
        if (print.cxx23) latest.insert(std::begin(cxx23_core), std::end(cxx23_core));
        if (print.cxx20) latest.insert(std::begin(cxx20_core), std::end(cxx20_core));
        if (print.cxx17) latest.insert(std::begin(cxx17_core), std::end(cxx17_core));
        if (print.cxx14) latest.insert(std::begin(cxx14_core), std::end(cxx14_core));
        if (print.cxx11) latest.insert(std::begin(cxx11_core), std::end(cxx11_core));
        std::snprintf(text, sizeof text, "ALL CORE MACROS UP TO C++%02i", latest_rev());
        show(text, latest);
    }
    latest.clear();
    if (print.lib_features)
    {   // keep reverse revision insersion order!
        if (print.cxx26) latest.insert(std::begin(cxx26_lib), std::end(cxx26_lib));
        if (print.cxx23) latest.insert(std::begin(cxx23_lib), std::end(cxx23_lib));
        if (print.cxx20) latest.insert(std::begin(cxx20_lib), std::end(cxx20_lib));
        if (print.cxx17) latest.insert(std::begin(cxx17_lib), std::end(cxx17_lib));
        if (print.cxx14) latest.insert(std::begin(cxx14_lib), std::end(cxx14_lib));
        std::snprintf(text, sizeof text, "ALL LIB MACROS UP TO C++%02i", latest_rev());
        show(text, latest);
    }
}

int main()
{
    if (print.general_features) show("C++ GENERAL", cxx_core);
    if (print.separated_revisions)
    {
        if (print.cxx11 && print.core_features) show("C++11 CORE", cxx11_core);
        if (print.cxx14 && print.core_features) show("C++14 CORE", cxx14_core);
        if (print.cxx14 && print.lib_features ) show("C++14 LIB" , cxx14_lib);
        if (print.cxx17 && print.core_features) show("C++17 CORE", cxx17_core);
        if (print.cxx17 && print.lib_features ) show("C++17 LIB" , cxx17_lib);
        if (print.cxx20 && print.core_features) show("C++20 CORE", cxx20_core);
        if (print.cxx20 && print.lib_features ) show("C++20 LIB" , cxx20_lib);
        if (print.cxx23 && print.core_features) show("C++23 CORE", cxx23_core);
        if (print.cxx23 && print.lib_features ) show("C++23 LIB" , cxx23_lib);
        if (print.cxx26 && print.core_features) show("C++26 CORE", cxx26_core);
        if (print.cxx26 && print.lib_features ) show("C++26 LIB" , cxx26_lib);
    }
    if (print.latest_revisions) show_latest();
    if (print.attributes) show("ATTRIBUTES", attributes);
}
