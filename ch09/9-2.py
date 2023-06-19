import gym

# 환경 불러오기
env=gym.make("FrozenLake-v0",is_slippery=False)
print(env.observation_space)
print(env.action_space)

n_trial=20

# 에피소드 수집
env.reset()
episode=[]
for i in range(n_trial):
    action=env.action_space.sample() # 행동을 취함(랜덤 선택)
    obs,reward,done,info=env.step(action) # 보상을 받고 상태가 바뀜
    episode.append([action,reward,obs])
    env.render()
    if done:
        break

print(episode)
env.close()