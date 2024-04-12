package com.qg.bean;

import com.qg.dao.impl.UserDaoImpl;
import com.qg.service.impl.UserServiceImpl;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

/**
 * 单例管理
 *
 * @author Sangby
 */
public class SingletonFactory {
    private static UserServiceImpl userServiceSingleton;

    private static UserDaoImpl userDaoSingleton;

    static{
        try{
            userServiceSingleton = (UserServiceImpl) getSingleByName(UserServiceImpl.class.getName());

            userDaoSingleton = (UserDaoImpl) getSingleByName(UserDaoImpl.class.getName());
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    /**
     * 按名称构造单例
     *
     * @param name 名字
     *
     * @return 对象
     *
     * @throws ClassNotFoundException    未找到类异常
     * @throws NoSuchMethodException     没有这样方法例外
     * @throws InvocationTargetException 调用目标异常
     * @throws InstantiationException    实例化异常
     * @throws IllegalAccessException    非法访问例外
     */
    private static Object getSingleByName(String name) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
        //反射获取class字节码
        Class<?> clazz = Class.forName(name);
        //根据字节码中的构造方法获取构造器
        Constructor<?> constructor = clazz.getDeclaredConstructor();
        //设置构造器可访问
        constructor.setAccessible(true);
        //通过构造器创建对象
        return constructor.newInstance();
    }
    public static UserServiceImpl getUserServiceSingleton() {
        return userServiceSingleton;
    }

    public static UserDaoImpl getUserDaoSingleton() {
        return userDaoSingleton;
    }
}
