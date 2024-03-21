package com.qg.jdbcutil.util;

import java.sql.PreparedStatement;
import java.sql.SQLException;
//要想用这个先要造一个类,再写一个接口实现类
public interface MyHandler<T> {

    /**
     * 处理字符集,返回一个对象
     * @param ps 预编译的Statement对象
     *
     * @return 返回处理结果
     * @throws SQLException
     */
    T handler(PreparedStatement ps) throws SQLException;
}
