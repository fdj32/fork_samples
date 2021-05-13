insert into users(username, password, enabled) values('admin', '$2a$10$rA3RkhKIhGgXfhftH2HxWej24Hn7S3C0q5xP3fRpgrX3prfxP8.u.', true); --BCryptPasswordEncoder
insert into users(username, password, enabled) values('user', '$2a$10$lQk.U31X7cZduogUEBccme3C8Hf/6.6C7drLeZpVt5bYClXeqkHdC', true);
insert into authorities(username, authority) values ('admin', 'ROLE_ADMIN');
insert into authorities(username, authority) values ('user', 'ROLE_USER');
